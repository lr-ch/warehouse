/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
class Solution {
	void bt(string &s, int i) {
		if (i == s.length()) res = max(res, subs.size());

		for (int j = i + 1; j <= s.length(); j++) {
			string sub = s.substr(i, j - i);
			if (!subs.count(sub)) {
				subs.insert(sub);
				bt(s, j);
				subs.erase(sub);
			}
		}
	}

	unordered_set<string> subs;
	size_t res = 0;
public:
	int maxUniqueSplit(string s) {
		bt(s, 0);
		return res;
	}
};
// @lc code=end
