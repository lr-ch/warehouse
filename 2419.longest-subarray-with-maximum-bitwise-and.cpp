/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int maxi = *max_element(nums.begin(), nums.end());

		int length = 0, curr = 0;
		for (auto& n : nums) {
			if (n == maxi) curr++;
			else curr = 0;

			length = max(length, curr);
		}


		return length;
	}
};
// @lc code=end
