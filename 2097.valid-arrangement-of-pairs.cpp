/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
		unordered_map<int, int> abs_degs;
		unordered_map<int, vector<int>> adjs;
		for (const auto& p : pairs) {
			int from = p[0], to = p[1];
			adjs[from].push_back(to);
			abs_degs[from]++;	// out degree
			abs_degs[to]--;		// in degree
		}

		int start = pairs[0][0];
		for (const auto& [n, d] : abs_degs)
			if (d == 1) {
				start = n;
				break;
			}

		vector<int> visited;
		stack<int> nodes;
		nodes.push(start);

		while (!nodes.empty()) {
			auto& candidates = adjs[nodes.top()];
			if (candidates.empty()) {
				visited.push_back(nodes.top());
				nodes.pop();
			} else {
				int next = candidates.back();
				nodes.push(next);
				candidates.pop_back();
			}
		}

		vector<vector<int>> ans;
		for (int i = visited.size() - 1; i > 0; i--)
			ans.push_back({ visited[i], visited[i - 1] });

		return ans;
	}
};
// @lc code=end
