/*
 * @lc app=leetcode id=330 lang=cpp
 * @lcpr version=30203
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		long miss = 1;
		int curr = 0, ans = 0;

		while (miss <= n) {
			if (curr < nums.size() && miss >= nums[curr]) {
				miss += nums[curr];
				curr++;
			} else {
				miss += miss;
				ans++;
			}
		}

		return ans;
	}
};
// @lc code=end
