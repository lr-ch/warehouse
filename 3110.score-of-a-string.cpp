/*
 * @lc app=leetcode id=3110 lang=cpp
 * @lcpr version=30203
 *
 * [3110] Score of a String
 */

// @lc code=start
class Solution {
public:
	int scoreOfString(string& s) {
		int ans = 0;
		for (int i = 0; i < s.length() - 1; i++)
			ans += abs(s[i] - s[i + 1]);
		return ans;
	}
};
// @lc code=end
