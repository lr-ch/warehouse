/*
 * @lc app=leetcode id=2065 lang=cpp
 *
 * [2065] Maximum Path Quality of a Graph
 */

// @lc code=start
class Solution {
	typedef pair<int, int> path;	// (next node, time)
public:
	int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
		unordered_map<int, vector<path>> graph(values.size());
		for (const auto& e : edges) {
			int from = e[0], to = e[1], time = e[2];
			graph[from].push_back({ to, time });
			graph[to].push_back({ from, time });
		}

		vector<bool> visited(values.size(), false);

		int maxScore = INT_MIN;
		function<void(int, int, int)> bt = [&](int node, int currTime, int currScore) {
			if (node == 0) maxScore = max(maxScore, currScore);

			for (const auto& [next, nextTime] : graph[node]) {
				if (currTime + nextTime <= maxTime) {
					if (!visited[next]) {
						visited[next] = true;
						bt(next, currTime + nextTime, currScore + values[next]);
						visited[next] = false;
					} else
						bt(next, currTime + nextTime, currScore);
				}
			}
		};

		visited[0] = true;
		bt(0, 0, values[0]);

		return maxScore;
	}
};
// @lc code=end
