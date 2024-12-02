/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution {
public:
	int isPrefixOfWord(const string& sentence, const string& searchWord) {
		int curr = 0, pos = 1;
		while (true) {
			if (sentence.substr(curr).starts_with(searchWord)) return pos;

			curr = sentence.find(' ', curr);
			if (curr == string::npos) break;

			curr++;
			pos++;
		}

		return -1;
	}
};
// @lc code=end
