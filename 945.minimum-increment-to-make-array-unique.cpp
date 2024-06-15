/*
 * @lc app=leetcode id=945 lang=cpp
 * @lcpr version=30203
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
	int minIncrementForUnique(vector<int>& nums) {
		int ans = 0, move = 0;
		sort(nums.begin(), nums.end());
		for (const auto& n : nums) {
			ans += max(move - n, 0);
			move = max(move, n) + 1;
		}
		return ans;
	}
};
// @lc code=end
