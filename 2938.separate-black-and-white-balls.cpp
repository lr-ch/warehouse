/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
class Solution {
public:
	long long minimumSteps(string s) {
		long long blacks = 0, swaps = 0;

		for (const auto& ch : s) {
			switch (ch) {
				case '0' :
					swaps += blacks;
					break;
				case '1' :
					blacks++;
					break;
			}
		}
		return swaps;
	}
};
// @lc code=end
