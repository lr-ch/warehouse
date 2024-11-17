/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k) {
		vector<long> presum(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); ++i)
			presum[i] = nums[i - 1] + presum[i - 1];

		deque<int> dq;
		int ans = INT_MAX;
		for (int i = 0; i <= nums.size(); ++i) {
			// remove negative nums indices
			while (!dq.empty() && presum[i] <= presum[dq.back()])
				dq.pop_back();

			while (!dq.empty() && presum[i] - presum[dq.front()] >= k) {
				ans = min(ans, i - dq.front());
				dq.pop_front();
			}

			dq.push_back(i);
		}
		return ans == INT_MAX ? -1 : ans;
	}
};
// @lc code=end
