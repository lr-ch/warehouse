/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
class Solution {
public:
	long long continuousSubarrays(vector<int>& nums) {
		deque<int> minq, maxq;	// store min/max values' indices in the window
		long long ans = 0;

		for (int left = 0, right = 0; right < nums.size(); ++right) {
			// maintain the min/max values' indices in the window
			while (!minq.empty() && nums[minq.back()] >= nums[right]) minq.pop_back();
			while (!maxq.empty() && nums[maxq.back()] <= nums[right]) maxq.pop_back();
			minq.push_back(right);
			maxq.push_back(right);

			// validate the window
			while (nums[maxq.front()] - nums[minq.front()] > 2) {
				left++;
				while (minq.front() < left) minq.pop_front();
				while (maxq.front() < left) maxq.pop_front();
			}

			ans += right - left + 1;
		}

		return ans;
	}
};
// @lc code=end
