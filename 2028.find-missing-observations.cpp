/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
class Solution {
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int sum = accumulate(rolls.begin(), rolls.end(), 0),
			expected = mean * (n + rolls.size()) - sum;

		if (expected < n || expected > 6 * n) return {};

		int expected_mean = expected / n, expected_mod = expected % n;
		vector<int> res(n, expected_mean);

		for (int i = 0; i < expected_mod; i++) res[i]++;
		return res;
	}
};
// @lc code=end
