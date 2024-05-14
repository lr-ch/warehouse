/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
class SolutionBFS {
	const array<pair<int, int>, 4> dirs = {{ { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } }};
public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();

		/*
		 * 1. m == grid.length
		 * 2. n == grid[i].length
		 * 3. 1 <= m, n <= 15
		 * Here gives 16 * 16 bits vector for visisted flag
		 */
		typedef bitset<256> visited;	// Index = R * 16 + C
		queue<tuple<int, int, int, visited>> q;

		int ans = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (grid[r][c] != 0) q.push({ r, c, 0, 0 });

				while (!q.empty()) {
					auto [cr, cc, cg, v] = q.front(); q.pop();
					if (!v[cr * 16 + cc]) {
						v[cr * 16 + cc] = true;
						int gold = cg + grid[cr][cc];
						ans = max(ans, gold);

						for (const auto& [dr, dc] : dirs) {
							int nr = cr + dr, nc = cc + dc;

							if (nr < 0 || nr >= R || nc < 0 || nc >= C || !grid[nr][nc] || v[nr * 16 + nc])
								continue;
							q.push({ nr, nc, gold, v });
						}
					}
				}
			}
		}

		return ans;
	}
};

class SolutionDFS {
	int dfs(int r, int c, vector<vector<int>>& g) {
		if (r < 0 || r >= R || c < 0 || c >= C || !g[r][c] || visited[r * 16 + c]) return 0;

		visited[r * 16 + c] = 1;
		int gold = INT_MIN;
		for (const auto& [dr, dc] : dirs)
			gold = max(gold, g[r][c] + dfs(r + dr, c + dc, g));
		visited[r * 16 + c] = 0;
		return gold;
	}

	int R, C;
	bitset<256> visited = 0;
	const array<pair<int, int>, 4> dirs = {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};
public:
	int getMaximumGold(vector<vector<int>>& grid) {
		R = grid.size();
		C = grid[0].size();

		int ans = INT_MIN;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				ans = max(ans, dfs(r, c, grid));

		return ans;
	}
};

class Solution {
	SolutionBFS bfs;
	SolutionDFS dfs;
public:
	int getMaximumGold(vector<vector<int>>& grid) {
	//	return bfs.getMaximumGold(grid);
		return dfs.getMaximumGold(grid);
	}
};
// @lc code=end
