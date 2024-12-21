/*
 * @lc app=leetcode id=2872 lang=cpp
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start
class Solution {
	int dfs(int curr, int parent, const vector<int>& values, int k) {
		long sum = values[curr];
		for (const auto& next : adjs[curr])
			if (next != parent)
				sum += dfs(next, curr, values, k);

		// if the sum of children and this node is divided by k --> this tree is a valid split
		if (0 == (sum % k)) ans++;
		return sum % k;
	}

	int ans = 0;
	unordered_map<int, vector<int>> adjs;
public:
	int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
		for (const auto& e : edges) {
			int v1 = e[0], v2 = e[1];
			adjs[v1].push_back(v2);
			adjs[v2].push_back(v1);
		}

		dfs(0, INT_MIN, values, k);
		return ans;
	}
};
// @lc code=end
