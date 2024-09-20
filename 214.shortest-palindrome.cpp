/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
	string dfs(const string& s) {
		int i = 0;
		for (int j = s.size() - 1; j >= 0; j--)
			if (s[i] == s[j]) i++;

		if (i == s.size()) return s;
		string rev = s.substr(i);
		reverse(rev.begin(), rev.end());
		return rev + dfs(s.substr(0, i)) + s.substr(i);
	}

public:
	string shortestPalindrome(string s) {
		return dfs(s);
	}
};
// @lc code=end

