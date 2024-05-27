/*
 * @lc app=leetcode id=1255 lang=cpp
 * @lcpr version=30202
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
class Solution {
	int bt(vector<string>& words, vector<int>& score, vector<int>& freq, int curr) {
		int res = 0;
		for (int i = curr; i < words.size(); i++) {
			int sum = 0;
			bool valid = true;

			// check word is valid and calculate its score
			for (const auto& ch : words[i]) {
				// here used letters should be rolled back later
				freq[ch - 'a']--;
				if (freq[ch - 'a'] < 0)
					valid = false;
				sum += score[ch - 'a'];
			}

			if (valid) {
				sum += bt(words, score, freq, i + 1);
				res = max(res, sum);
			}

			// roll back used letters
			for (const auto& ch : words[i])
				++freq[ch - 'a'];
		}
		return res;
	}

public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> freq(26, 0);
		for (const auto& ch : letters) freq[ch - 'a']++;

		return bt(words, score, freq, 0);
	}
};
// @lc code=end
