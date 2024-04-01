/*
 * @lc app=leetcode id=58 lang=cpp
 * @lcpr version=30121
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
	int lengthOfLastWord(string s) {
		auto last = s.rbegin(), curr = last;

		while (*curr == ' ') curr++;
		last = curr;
		while (curr != s.rend() && *curr != ' ') curr++;
		return distance(last, curr);
	}
};
// @lc code=end
