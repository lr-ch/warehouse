/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
class Solution {
	int dfs(vector<int>& n, int i, int s) {
		if (i == n.size()) return s == maxOr ? 1 : 0;
		return dfs(n, i + 1, s) + dfs(n, i + 1, s | n[i]);
	}

	int maxOr = 0;
public:
	int countMaxOrSubsets(vector<int>& nums) {
		for_each(nums.begin(), nums.end(), [&](const auto &n) { maxOr |= n; });
		return dfs(nums, 0, 0);
	}
};
// @lc code=end
