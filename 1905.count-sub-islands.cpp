/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {
	void traverse(int r, int c, vector<vector<int>>& g) {
		queue<pair<int, int>> q;
		q.push({r, c});
		g[r][c] = 0;

		while (!q.empty()) {
			auto [cr, cc] = q.front(); q.pop();
			for (const auto& [dr, dc] : dirs) {
				int nr = cr + dr, nc = cc + dc;
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && g[nr][nc]) {
					q.push({nr, nc});
					g[nr][nc] = 0;
				}
			}
		}
	}

	int R, C;
	array<pair<int, int>, 4> dirs = {{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} }};
public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		R = grid2.size(), C = grid2[0].size();

		// grid1 AND grid2, clear set bits in grid2 if bits is unset in grid1
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				if (!grid1[r][c] && grid2[r][c])
					traverse(r, c, grid2);

		// now count islands in grid2
		int ans = 0;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				if (grid2[r][c]) {
					ans++;
					traverse(r, c, grid2);
				}

		return ans;
	}
};
// @lc code=end

