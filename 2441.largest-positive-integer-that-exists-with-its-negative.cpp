/*
 * @lc app=leetcode id=2441 lang=cpp
 * @lcpr version=30122
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */

// @lc code=start
class Solution {
public:
	int findMaxK(vector<int>& nums) {
		set<int, greater<int>> positive, negative;
		for (const auto& n : nums)
			if (n > 0) positive.insert(n);
			else negative.insert(n);

		for (const auto& p : positive)
			if (negative.count(-p)) return p;

		return -1;
	}
};
// @lc code=end
