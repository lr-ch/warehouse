/*
 * @lc app=leetcode id=552 lang=cpp
 * @lcpr version=30202
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
class Solution {
	/*
	 * dfs[n][A][L] : eligible combinations with n length record and total A absence and
	 *                consecutive L lates
	 */
	int dfs(int n, int A, int L) {
		// not eligible
		if (A >= 2 || L >= 3) return 0;
		// base case
		if (n == 0) return 1;

		if (memo[n][A][L] != INT_MIN) return memo[n][A][L];

		int res = dfs(n - 1, A, 0) % MOD;			// take 'P' for current poistion
		res = (res + dfs(n - 1, A + 1, 0)) % MOD;	// take 'A' for current position
		res = (res + dfs(n - 1, A, L + 1)) % MOD;	// take 'L' for current poistion

		return memo[n][A][L] = res;
	}

	vector<vector<vector<int>>> memo;
	const int MOD = 1e9 + 7;
public:
	int checkRecord(int n) {
		memo.resize(n + 1, vector<vector<int>>(2, vector<int>(3, INT_MIN)));
		return dfs(n, 0, 0);
	}
};
// @lc code=end
