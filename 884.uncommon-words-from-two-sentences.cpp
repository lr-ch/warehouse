/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
	unordered_map<string, int> str_split(const string& s) {
		unordered_map<string, int> ans;
		int start = 0, end = 0;
		while (string::npos != (end = s.find(" ", end))) {
			ans[s.substr(start, end - start)]++;
			start = ++end;
		}
		// last word
		ans[s.substr(start, end - start)]++;
		return ans;
	}

public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		auto total = str_split(s1);
		for (auto& [w, c] : str_split(s2))
			total[w] += c;

		vector<string> ans;
		for (auto& [w, c] : total)
			if (c == 1) ans.push_back(w);
		return ans;
	}
};
// @lc code=end

