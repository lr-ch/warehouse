/*
 * @lc app=leetcode id=514 lang=cpp
 * @lcpr version=30122
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int rlen = ring.length(), klen = key.size();
		// dp[i][j] : the minimun steps when key[i] is entered with ring[j] at 12 o'clock
		vector<vector<int>> dp(klen, vector<int>(rlen, INT_MAX));

		unordered_map<char, vector<int>> char2idx;
		for (int i = 0; i < rlen; i++) char2idx[ring[i]].push_back(i);

		// find out the minimun step at first character
		for (auto& idx : char2idx[key[0]]) dp[0][idx] = min(dp[0][idx], min(idx, rlen - idx));

		for (int i = 1; i < klen; i++)
			for (auto& cur_idx : char2idx[key[i]])
				for (auto& prev_idx : char2idx[key[i - 1]])
					dp[i][cur_idx] = min(
										dp[i][cur_idx],
										dp[i - 1][prev_idx] + min(
																abs(cur_idx - prev_idx),         // clockwise
																rlen - abs(cur_idx - prev_idx)   // c-clockwise
																)
										);

		int ans = INT_MAX;
		for (auto& idx : char2idx[key[klen - 1]])
			ans = min(ans, dp[klen - 1][idx]);

		return ans + klen /* push button times */;
	}
};
// @lc code=end
