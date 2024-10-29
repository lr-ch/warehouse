/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
class Solution {
	array<pair<int, int>, 3> dirs = {{
		{ -1, 1 }, { 0, 1 }, { 1, 1 }
	}};
public:
	int maxMoves(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();
		vector<vector<bool>> v(R, vector<bool>(C, false));
		queue<tuple<int, int, int>> q;		// (row, col, moves)
		for (int r = 0; r < R; r++) q.push({ r, 0, 0 });

		int ans = INT_MIN;
		while (!q.empty()) {
			auto [r, c, m] = q.front(); q.pop();
			ans = max(ans, m);

			for (const auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc;
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] > grid[r][c] && !v[nr][nc]) {
					q.push({ nr, nc, m + 1 });
					v[nr][nc] = true;
				}
			}
		}

		return ans;
	}
};
// @lc code=end
