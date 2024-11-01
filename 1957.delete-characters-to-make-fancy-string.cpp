/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution {
public:
	string makeFancyString(string s) {
		char last = ' ';
		int count = 0;
		string res;

		for (const auto ch : s) {
			if (last != ch) {
				last = ch;
				count = 1;
				res += last;
			} else if (count < 2) {
				res += ch;
				count++;
			}
		}
		return res;
	}
};
// @lc code=end
