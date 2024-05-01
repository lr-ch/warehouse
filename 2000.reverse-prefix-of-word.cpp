/*
 * @lc app=leetcode id=2000 lang=cpp
 * @lcpr version=30122
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
class Solution {
public:
	string reversePrefix(string word, char ch) {
		auto iter = word.begin();
		int i = 0;
		for (; i + iter != word.end(); i++)
			if (*(iter + i) == ch) break;

		if (i + iter == word.end()) return word;

		reverse(iter, iter + i + 1);
		return word;
	}
};
// @lc code=end
