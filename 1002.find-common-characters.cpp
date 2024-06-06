/*
 * @lc app=leetcode id=1002 lang=cpp
 * @lcpr version=30203
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
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
// @lc code=end
