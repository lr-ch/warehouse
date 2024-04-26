/*
 * @lc app=leetcode id=1289 lang=cpp
 * @lcpr version=30122
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
	int dfs(vector<vector<int>>& g, int Row, int Col, vector<vector<int>>& m) {
		if (Row < 0 || Row >= R || Col < 0 || Col >= C) return INT_MAX;
		if (Row == 0) return g[Row][Col];

		if (m[Row][Col] != INT_MAX) return m[Row][Col];

		for (int c = 0; c < C; c++) {
			if (c == Col) continue;
			m[Row][Col] = min(m[Row][Col], dfs(g, Row - 1, c, m));
		}

		return m[Row][Col] += g[Row][Col];
	}

	int R, C;
public:
	int minFallingPathSum(vector<vector<int>>& grid) {
		R = grid.size(), C = grid[0].size();
		vector<vector<int>> memo(R, vector<int>(C, INT_MAX));

		int ans = INT_MAX;
		for (int c = 0; c < C; c++)
			ans = min(ans, dfs(grid, R - 1, c, memo));
		return ans;
	}
};
// @lc code=end
