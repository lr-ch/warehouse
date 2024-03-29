/*
 * @lc app=leetcode id=2962 lang=cpp
 * @lcpr version=30121
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 */

// @lc code=start
class Solution {
public:
	long long countSubarrays(vector<int>& nums, int k) {
		int maxN = *max_element(nums.begin(), nums.end());
		vector<int> indices;    // index where maxN(s) reside

		long long ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == maxN) indices.push_back(i);

			if (indices.size() >= k)
				ans += indices[indices.size() - k] + 1;
		}

		return ans;
	}
};
// @lc code=end
