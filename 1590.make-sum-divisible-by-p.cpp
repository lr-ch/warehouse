/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		long total = accumulate(nums.begin(), nums.end(), 0L);
		if (total % p == 0) return 0;

		unordered_map<int, int> preTable;
		preTable[0] = -1;	// case of no answer

		int target = total % p, preSum = 0, ans = INT_MAX;

		for (int i = 0; i < nums.size(); i++) {
			preSum = (preSum + nums[i]) % p;

			int remain = (preSum - target + p) % p;
			if (preTable.count(remain))
				ans = min(ans, i - preTable[remain]);

			preTable[preSum] = i;
		}
		return ans >= nums.size() ? -1 : ans;
	}
};
// @lc code=end
