/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
	bool isPalindromeString(const string &s) {
		size_t i1 = 0, i2 = s.length() - 1;
		while (i1 < i2)
			if (s[i1++] != s[i2--]) return false;
		return true;
	}
public:
	bool isPalindrome(int x) {
		return isPalindromeString(to_string(x));
	}
};
// @lc code=end
