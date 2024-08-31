/*
 * @lc app=leetcode id=2699 lang=cpp
 *
 * [2699] Modify Graph Edge Weights
 */

// @lc code=start
class Solution {
	static constexpr int UNCONNECTED = 1e9 + 7;
public:
	vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
		vector<vector<int>> graph(n, vector<int>(n, UNCONNECTED));
		vector<vector<bool>> modified(n, vector<bool>(n, false));

		// generate graph
		for (const auto& e : edges) {
			int a = e[0], b = e[1], w = e[2];
			if (w == -1) {
				modified[a][b] = true;
				modified[b][a] = true;
				w = 1;
			}
			graph[a][b] = w;
			graph[b][a] = w;
		}

		// calculate shortest path from destination to each nodes
		vector<int> distFromDest(n, UNCONNECTED);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.push({ 0, destination });
		while (!pq.empty()) {
			auto [dist, curr] = pq.top(); pq.pop();
			if (distFromDest[curr] != UNCONNECTED) continue;		// already visited

			distFromDest[curr] = dist;
			for (int next = 0; next < n; next++) {
				int w = graph[curr][next];
				if (w != UNCONNECTED) pq.push({ dist + w, next });
			}
		}

		// calculate shortest path from source to each nodes
		vector<int> distFromSource(n, UNCONNECTED);
		pq.push({ 0, source });
		while (!pq.empty()) {
			auto [dist, curr] = pq.top(); pq.pop();
			if (distFromSource[curr] != UNCONNECTED) continue;		// already visited

			distFromSource[curr] = dist;

			// if the shortest path to destination is not the target
			if (curr == destination && dist != target) return {};

			for (int next = 0; next < n; next++) {
				int w = graph[curr][next];
				if (w == UNCONNECTED) continue;

				/*
				*   source -> ... -> curr -?-> next ... -> destination
				*
				*   Q : if "?" is modifiable, what value will it be?
				*   A : target - (distance between source to curr + distance between next to destination)
				*/
				if (modified[curr][next] && distFromSource[curr] + w + distFromDest[next] < target) {
					w = target - (distFromSource[curr] + distFromDest[next]);
					graph[curr][next] = w;
					graph[next][curr] = w;
				}
				pq.push({ dist + w, next });
			}
		}

		// return graph to function argument
		for (auto& e : edges)
			e[2] = graph[e[0]][e[1]];

		return edges;
	}
};
// @lc code=end
