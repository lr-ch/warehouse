/*
 * @lc app=leetcode id=1002 lang=cpp
 * @lcpr version=30203
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class SolutionSet {
public:
	vector<string> commonChars(vector<string>& words) {
		vector<multiset<char>> dict;
		for (const auto& s : words)
			dict.push_back(multiset<char>(s.begin(), s.end()));
		vector<size_t> common(26, INT_MAX);
		for (char ch = 'a'; ch <= 'z'; ch++)
			for (int i = 0; i < dict.size(); i++)
				common[ch - 'a'] = min(common[ch - 'a'], dict[i].count(ch));
		vector<string> ans;
		for (int i = 0; i < common.size(); i++)
			if (common[i] != 0)
				for (int j = 0; j < common[i]; j++)
					ans.push_back(string(1, 'a' + i));
		return ans;
	}
};

class SolutionArray {
public:
	vector<string> commonChars(vector<string>& words) {
		vector<vector<int>> freq(words.size(), vector<int>(26, 0));
		for (int i = 0; i < words.size(); i++)
			for (const auto& ch : words[i])
				freq[i][ch - 'a']++;

		vector<string> ans;
		// scan by column
		for (int alpha = 0; alpha < 26; alpha++) {
			int min_freq = INT_MAX;
			// check each row (word in words)
			for (int word = 0; word < freq.size(); word++)
				min_freq = min(min_freq, freq[word][alpha]);

			for (int i = 0; i < min_freq; i++)
				ans.push_back(string(1, 'a' + alpha));
		}
		return ans;
	}
};

class Solution {
	SolutionSet MultiSet;
	SolutionArray Array;
public:
	vector<string> commonChars(vector<string>& words) {
	//	return MultiSet.commonChars(words);
		return Array.commonChars(words);
	}
};
// @lc code=end
