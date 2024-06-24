/*
 * @lc app=leetcode id=995 lang=cpp
 * @lcpr version=30204
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
class Solution {
public:
	int minKBitFlips(vector<int>& nums, int k) {
		int flips = 0, count = 0;
		vector<int> memo(nums.size() + 1, 0);			// memo of flip counts at nums[i]

		for (int i = 0; i < nums.size(); i++) {
			flips += memo[i];

			if ((nums[i] + flips % 2) == 1) continue;	// no flip needed

			// overflow
			if (i + k > nums.size()) return -1;

			// nums[i] + flips % 2 -> 0, so flip nums[i]
			flips++;

			// only nums[i..k] are flipped, elements after nums[k + 1] are not
			memo[i + k] -= 1;

			count++;
		}
		return count;
	}
};
// @lc code=end
