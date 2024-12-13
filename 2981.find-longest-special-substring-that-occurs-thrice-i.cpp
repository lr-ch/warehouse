/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start
class Solution {
public:
	int maximumLength(string s) {
		unordered_map<string, int> dict;
		for (int left = 0; left < s.length(); left++) {
			string tmp;
			for (int right = left; right < s.length(); right++) {
				if (tmp.empty() || tmp.back() == s[right]) {
					tmp.push_back(s[right]);
					dict[tmp]++;
				} else
					break;
			}
		}
		int ans = 0;
		for (const auto& [str, count] : dict)
			if (count >= 3)
				ans = max(ans, (int)str.length());
		return ans == 0 ? -1 : ans;
	}
};
// @lc code=end
