/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
class Solution {
public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		// split string by space
		istringstream s1(sentence1), s2(sentence2);
		deque<string> dq1((istream_iterator<string>(s1)), istream_iterator<string>());
		deque<string> dq2((istream_iterator<string>(s2)), istream_iterator<string>());

		while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
			dq1.pop_front();
			dq2.pop_front();
		}

		while (!dq1.empty() &&!dq2.empty() && dq1.back() == dq2.back()) {
			dq1.pop_back();
			dq2.pop_back();
		}

		return dq1.empty() || dq2.empty();
	}
};
// @lc code=end
