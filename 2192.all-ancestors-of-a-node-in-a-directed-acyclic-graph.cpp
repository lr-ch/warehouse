/*
 * @lc app=leetcode id=2192 lang=cpp
 * @lcpr version=30204
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution {
	void dfs(unordered_set<int>& v, int curr) {
		v.insert(curr);

		for (const auto& prev : adjs[curr])
			if (!v.count(prev))
				dfs(v, prev);
	}

	unordered_map<int, unordered_set<int>> adjs;
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		for (const auto& e : edges) adjs[e[1]].insert(e[0]);

		vector<vector<int>> ans(n);
		for (int i = 0; i < n; i++) {
			unordered_set<int> visited;
			vector<int> neighbors;
			dfs(visited, i);	// find all connected neighbors in visited[]
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (visited.count(j)) neighbors.push_back(j);
			}

			ans[i] = neighbors;
		}
		return ans;
	}
};
// @lc code=end
