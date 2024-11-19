/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
class Solution {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		unordered_set<int> s;
		int left = 0, right = 0;
		long long ans = INT_MIN, sum = 0;

		while (right < nums.size()) {
			if (s.count(nums[right])) {
				s.erase(nums[left]);
				sum -= nums[left++];
			} else {
				s.insert(nums[right]);
				sum += nums[right++];
			}

			if (s.size() < k) continue;

			ans = max(ans, sum);

			s.erase(nums[left]);
			sum -= nums[left++];
		}

		return ans == INT_MIN ? 0 : ans;
	}
};
// @lc code=end
