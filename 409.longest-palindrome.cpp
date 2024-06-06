/*
 * @lc app=leetcode id=409 lang=cpp
 * @lcpr version=30203
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
	int longestPalindrome(string s) {
		unordered_set<char> freq;	// odd or even times
		int ans = 0;
		for (const auto& ch : s) {
			if (freq.count(ch)) {
				freq.erase(ch);		// even times
				ans += 2;
			} else
				freq.insert(ch);	// odd times
		}
		// if freq is empty, all chars appears even times
		// or we can choose any char in freq as center of
		// palindrome
		return freq.empty() ? ans : ans + 1;
	}
};
// @lc code=end
