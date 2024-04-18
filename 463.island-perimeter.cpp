/*
 * @lc app=leetcode id=463 lang=cpp
 * @lcpr version=30122
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size(), ans = 0;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (!grid[r][c]) continue;

				int edge = 4;

				// check horizontal neighbor
				if (c - 1 >= 0 && grid[r][c - 1]) edge--;
				if (c + 1  < C && grid[r][c + 1]) edge--;

				// check vertical neighbor
				if (r - 1 >= 0 && grid[r - 1][c]) edge--;
				if (r + 1  < R && grid[r + 1][c]) edge--;

				ans += edge;
			}
		}
		return ans;
	}
};
// @lc code=end
