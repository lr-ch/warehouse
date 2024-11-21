/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
class Solution {
public:
	int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		// matrix[r][c] =
		//  0 - safe
		//  1 - guard's walk path
		//  2 - guard's initial position
		//  3 - wall
		vector<vector<int>> matrix(m, vector<int>(n));

		// mark up guards
		for (const auto& g : guards) matrix[g[0]][g[1]] = 2;

		// mark up walls
		for (const auto& w : walls) matrix[w[0]][w[1]] = 3;

		// mark up guard's walk
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < n; c++) {
				if (matrix[r][c] != 2) continue;	// not a guard

				for (int up = r - 1; up >= 0; matrix[up--][c] = 1)
					if (matrix[up][c] >= 2) break;		// guard or wall
				for (int down = r + 1; down < m; matrix[down++][c] = 1)
					if (matrix[down][c] >= 2) break;	// guard or wall
				for (int left = c - 1; left >= 0; matrix[r][left--] = 1)
					if (matrix[r][left] >= 2) break;	// guard or wall
				for (int right = c + 1; right < n; matrix[r][right++] = 1)
					if (matrix[r][right] >= 2) break;	// guard or wall
			}
		}

		int ans = 0;
		for_each(matrix.begin(), matrix.end(), [&ans](const auto& v) {
			for_each(v.begin(), v.end(), [&ans](const auto& grid) {
				if (grid == 0) ans++;
			});
		});

		return ans;
	}
};
// @lc code=end
