/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution {
public:
	int minBitFlips(int start, int goal) {
		return bitset<32>(start ^ goal).count();
	}
};
// @lc code=end
