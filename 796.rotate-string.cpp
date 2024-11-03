/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
	bool rotateString(string s, string goal) {
		for (int i = 0; i < s.length(); i++)
			if (s.substr(i, s.length() - i) + s.substr(0, i) == goal)
				return true;
		return false;
	}
};
// @lc code=end
