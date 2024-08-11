/*
 * @lc app=leetcode id=1568 lang=cpp
 * @lcpr version=30204
 *
 * [1568] Minimum Number of Days to Disconnect Island
 */

// @lc code=start
class Solution {
	/*
	 * [200] Number of Islands
	 */
	int numIslands(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int ans = 0;

		function<int(int, int)> dfs = [&](int r, int c) {
			if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return 0;
			if (grid[r][c] == 0 || visited[r][c]) return 0;

			visited[r][c] = true;
			for (const auto& [dr, dc] : dirs) dfs(r + dr, c + dc);
			return 1;
		};

		for (int r = 0; r < grid.size(); r++)
			for (int c = 0; c < grid[0].size(); c++)
				ans += dfs(r, c);
		return ans;
	}

	array<pair<int, int>, 4> dirs = {{ {1, 0}, {0, -1}, {-1, 0}, {0, 1} }};
public:
	int minDays(vector<vector<int>>& grid) {
		// The grid is said to be connected if we have exactly one island,
		// otherwise is said disconnected
		if (numIslands(grid) == 1) {
			for (int r = 0; r < grid.size(); r++) {
				for (int c = 0; c < grid[r].size(); c++) {
					if (grid[r][c] == 1) {
						grid[r][c] = 0;
						if (numIslands(grid) != 1) return 1;
						grid[r][c] = 1;
					}
				}
			}
			return 2;
		}
		return 0;
	}
};
// @lc code=end
