/*
 * @lc app=leetcode id=1248 lang=cpp
 * @lcpr version=30204
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
	int count(const vector<int>& nums, int k) {
		int left = 0, odds = 0, ans = 0;
		for (int right = 0; right < nums.size(); ++right) {
			odds += nums[right] % 2;

			while (odds > k)
				odds -= nums[left++] % 2;

			ans += right - left + 1;
		}
		return ans;
	}

public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		return count(nums, k) - count(nums, k - 1);
	}
};
// @lc code=end
