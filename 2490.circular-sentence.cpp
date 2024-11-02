/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start
class Solution {
public:
	bool isCircularSentence(string sentence) {
		char last = ' ';
		bool isHead = false;
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == ' ') {
				last = sentence[i - 1];
				isHead = true;
				continue;
			}
			if (isHead) {
				if (sentence[i] != last) return false;
				isHead = false;
			}
		}

		return sentence.back() == sentence.front();
	}
};
// @lc code=end

