/*
 * @lc app=leetcode id=1509 lang=cpp
 * @lcpr version=30204
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
	int minDifference(vector<int>& nums) {
		int n = nums.size();

		// make every number the same
		if (n <= 4) return 0;

		sort(nums.begin(), nums.end());
		int ans = INT_MAX;
		for (int i = 0; i <= 3; i++)
			ans = min(ans, nums[n - 4 + i] - nums[i]);

		return ans;
	}
};
// @lc code=end
