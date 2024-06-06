/*
 * @lc app=leetcode id=2486 lang=cpp
 * @lcpr version=30203
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
class Solution {
public:
	int appendCharacters(string s, string t) {
		int si = 0, ti = 0;
		while (si < s.length() && ti < t.length()) {
			if (s[si] == t[ti])
				ti++;
			si++;
		}
		return t.length() - ti;
	}
};
// @lc code=end
