/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
class Solution {
public:
	int waysToSplitArray(vector<int>& nums) {
		vector<long> preSum(nums.begin(), nums.end());
		for (int i = 1; i < preSum.size(); i++) preSum[i] += preSum[i - 1];

		int ans = 0;
		for (int i = 0; i < preSum.size() - 1; i++)
			if (preSum[i] >= preSum.back() - preSum[i])
				ans++;
		return ans;
	}
};
// @lc code=end
