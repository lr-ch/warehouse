/*
 * @lc app=leetcode id=1289 lang=cpp
 * @lcpr version=30122
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class SolutionTopDown {
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

class SolutionBottomUp {
public:
	int minFallingPathSum(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();
		vector<vector<int>> memo(R, vector<int>(C, 0));

		memo[0] = grid[0];						// init level 0
		for (int Row = 1; Row < R; Row++) {		// start from level 1
			for (int Col = 0; Col < C; Col++) {
				memo[Row][Col] = INT_MAX;

				for (int prevCol = 0; prevCol < C; prevCol++) {
					if (prevCol == Col) continue;
					memo[Row][Col] = min(memo[Row][Col], memo[Row - 1][prevCol] + grid[Row][Col]);
				}
			}
		}

		return *min_element(memo[R - 1].begin(), memo[R - 1].end());
	}
};

class Solution {
	/*
	 * Accepted
	 *  16/16 cases passed (458 ms)
	 *  Your runtime beats 5.26 % of cpp submissions
	 *  Your memory usage beats 16.18 % of cpp submissions (18.3 MB)
	 */
	SolutionTopDown		topDown;

	/*
	 * Accepted
	 *  16/16 cases passed (257 ms)
	 *  Your runtime beats 43.28 % of cpp submissions
	 *  Your memory usage beats 57.11 % of cpp submissions (18.2 MB)
	 */
	SolutionBottomUp	bottomUp;
public:
	int minFallingPathSum(vector<vector<int>>& grid) {
	//	return topDown.minFallingPathSum(grid);
		return bottomUp.minFallingPathSum(grid);
	}
};

// @lc code=end
