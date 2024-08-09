/*
 * @lc app=leetcode id=840 lang=cpp
 * @lcpr version=30204
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution {
	bool isValid(vector<vector<int>>& grid, int r, int c) {
		vector<bool> used(10, false);
		for (int i = r; i < r + 2; i++) {
			for (int j = c; j < c + 2; j++) {
				if (grid[i][j] < 1 || grid[i][j] > 9 || used[grid[i][j]])
					return false;
				used[grid[i][j]] = true;
			}
		}
		return true;
	}

public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		if (grid.size() < 3 || grid[0].size() < 3) return 0;

		int ans = 0;
		for (int r = 0; r < grid.size() - 2; r++) {
			for (int c = 0; c < grid[0].size() - 2; c++) {
				if (!isValid(grid, r, c)) continue;

				int sumR1 = grid[  r  ][c] + grid[  r  ][c + 1] + grid[  r  ][c + 2];
				int sumR2 = grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2];
				int sumR3 = grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
				if (sumR1 != sumR2 || sumR2 != sumR3) continue;

				int sumC1 = grid[r][  c  ] + grid[r + 1][  c  ] + grid[r + 2][  c  ];
				int sumC2 = grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1];
				int sumC3 = grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2];
				if (sumC1 != sumC2 || sumC2 != sumC3) continue;

				int sumD1 = grid[r][  c  ] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
				int sumD2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][  c  ];
				if (sumD1 != sumD2 || sumC1 != sumD1 || sumR1 != sumD2 || sumD1 != 15) continue;

				ans++;
			}
		}
		return ans;
	}
};
// @lc code=end
