/*
 * @lc app=leetcode id=633 lang=cpp
 * @lcpr version=30203
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
	bool judgeSquareSum(int c) {
		int a = sqrt(c);
		for (int i = 0; i < a + 1; i++) {
			int b = sqrt(c - i * i);
			if (b * b + i * i == c) return true;
		}
		return false;
	}
};
// @lc code=end
