/*
 * @lc app=leetcode id=2582 lang=cpp
 * @lcpr version=30204
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution {
public:
	int passThePillow(int n, int time) {
		int turns = time / (n - 1), remains = time % (n - 1);
		return (turns % 2 ? n - remains : remains + 1);
	}
};
// @lc code=end
