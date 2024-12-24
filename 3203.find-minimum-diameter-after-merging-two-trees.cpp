/*
 * @lc app=leetcode id=3203 lang=cpp
 *
 * [3203] Find Minimum Diameter After Merging Two Trees
 */

// @lc code=start
class Solution {
	int treeDiameter(vector<vector<int>>& edges) {
		if (edges.empty()) return 0;

		unordered_map<int, vector<int>> adjs;
		int max_id = INT_MIN;							// only for creating visited array
		for (const auto& e : edges) {
			adjs[e[0]].push_back(e[1]);
			adjs[e[1]].push_back(e[0]);
			max_id = max({max_id, e[0], e[1]});
		}

		// input  : start node id
		// output : (diameter of the start node, the farthest node id)
		auto calcDiameter = [&adjs, &max_id](int start) -> pair<int, int> {
			vector<bool> visited(max_id + 1, false);	// count from 0
			queue<int> q;
			q.push(start);
			int diameter = 0, last = -1;
			while (!q.empty()) {
				int qsize = q.size();
				while (qsize--) {
					int curr = q.front(); q.pop();
					last = curr;
					visited[curr] = true;
					for (const auto& next : adjs[curr])
						if (!visited[next]) q.push(next);
				}
				diameter++;
			}
			return { diameter, last };
		};

		// start from a random node, find the farthest node
		auto [_, farthest] = calcDiameter(edges[0][0]);

		// this farthest node must be one of the endpoints on the diameter,
		// so start from it to calculate the real diameter
		auto [diameter, _] = calcDiameter(farthest);
		return diameter - 1;
	}

public:
	int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
		int d1 = treeDiameter(edges1), d2 = treeDiameter(edges2);
		return max({ d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1 });
	}
};
// @lc code=end
