/*
 * @lc app=leetcode id=2134 lang=cpp
 * @lcpr version=30204
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution {
public:
	int minSwaps(vector<int>& nums) {
		// decide window size (how many '1's)
		int count_one = accumulate(nums.begin(), nums.end(), 0);

		// initialize flips times in first window
		int flips = count(nums.begin(), nums.begin() + count_one, 0);

		// slide window and record the minimun flip times
		int ans = flips;
		for (int left = 1; left < nums.size(); left++) {
			int right = (left + count_one - 1) % nums.size();	// circular array

			if (nums[left - 1] == 0) flips--;
			if (nums[right] == 0) flips++;

			ans = min(ans, flips);
		}
		return ans;
	}
};
// @lc code=end
