/*
 * @lc app=leetcode id=1438 lang=cpp
 * @lcpr version=30204
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		int left = 0, length = INT_MIN;
		multiset<int> window;

		for (int right = 0; right < nums.size(); right++) {
			window.insert(nums[right]);
			while (*window.rbegin() - *window.begin() > limit)
			//	window.erase(nums[left++]);
				window.erase(window.find(nums[left++]));	// only remove the most left one

			length = max(length, right - left + 1);
		}

		return length;
	}
};
// @lc code=end
