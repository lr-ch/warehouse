/*
 * @lc app=leetcode id=2370 lang=cpp
 * @lcpr version=30122
 *
 * [2370] Longest Ideal Subsequence
 */

// @lc code=start
class Solution {
public:
	int longestIdealString(string s, int k) {
		array<int, 26> dp;					// dp[i], the longest length string end with ascii (i + 'a')
		fill(dp.begin(), dp.end(), 0);

		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			int longest = 0;
			for (int j = 0; j < dp.size(); j++)
				if (abs(s[i] - 'a' - j) <= k)
					longest = max(longest, dp[j]);

			dp[s[i] - 'a'] = max(dp[s[i] - 'a'], longest + 1);	// dp[j] + s[i] (this ch)
			ans = max(ans, dp[s[i] - 'a']);
		}
		return ans;
	}
};
// @lc code=end
