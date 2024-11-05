/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
class Solution {
public:
	int minChanges(string s) {
		int change = 0;

		for (int i = 0; i < s.length(); i += 2)
			if (s[i] != s[i + 1]) change++;

		return change;
	}
};
// @lc code=end
