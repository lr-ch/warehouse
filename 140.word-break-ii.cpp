/*
 * @lc app=leetcode id=140 lang=cpp
 * @lcpr version=30202
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
	string combine(vector<string>& v) {
		string res;
		for (const auto& s : v) res.append(s + ' ');
		// trim off trailing space
		res.pop_back();
		return res;
	}

	void dfs(string& s, unordered_set<string>& dict, int at, vector<string>& curr) {
		if (at >= s.length()) {
			ans.push_back(combine(curr));
			return;
		}

		for (int cut = at + 1; cut <= s.length(); cut++) {
			string tmp = s.substr(at, cut - at);

			if (dict.count(tmp)) {
				curr.push_back(tmp);
				dfs(s, dict, cut, curr);
				curr.pop_back();
			}
		}
	}

	vector<string> ans;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<string> curr;
		dfs(s, dict, 0, curr);
		return ans;
	}
};
// @lc code=end
