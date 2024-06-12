/*
 * @lc app=leetcode id=75 lang=cpp
 * @lcpr version=30203
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
	void sortColors(vector<int>& nums) {
		array<int, 3> freq;		// red, white, blue
		for (const auto& n : nums) freq[n]++;
		nums.assign(freq[0], 0);
		nums.insert(nums.end(), freq[1], 1);
		nums.insert(nums.end(), freq[2], 2);
	}
};
// @lc code=end
