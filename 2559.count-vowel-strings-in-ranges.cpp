/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution {
public:
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		unordered_set<char> vowels({ 'a', 'e', 'i', 'o', 'u' });
		vector<int> preSum(words.size() + 1, 0);
		for (int i = 0; i < words.size(); i++) {
			preSum[i + 1] = preSum[i];
			if (vowels.count(words[i].front()) && vowels.count(words[i].back()))
				preSum[i + 1]++;
		}

		vector<int> res(queries.size());
		for (int i = 0; i < queries.size(); i++)
			res[i] = preSum[queries[i][1] + 1] - preSum[queries[i][0]];
		return res;
	}
};
// @lc code=end
