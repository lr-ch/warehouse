/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
class Solution {
public:
	string compressedString(string word) {
		string res;
		int pos = 1, cnt = 1;
		while (true) {
			while (pos < word.size() && word[pos] == word[pos - 1] && cnt < 9) {
				cnt++;
				pos++;
			}
			res += to_string(cnt) + word[pos - 1];
			cnt = 1;
			if (++pos > word.size()) break;
		}
		return res;
	}
};
// @lc code=end
