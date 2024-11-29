/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start
class Solution {
	const array<pair<int, int>, 4> dirs = {{
										{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
									}};
public:
	int minimumTime(vector<vector<int>>& grid) {
		// stuck at begining
		if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

		int R = grid.size(), C = grid[0].size();

		// least time to arrive grid[r][c]
		vector<vector<int>> visitTime(R, vector<int>(C, -1));

		// (arrival time, row, col)
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
		pq.push({ 0, 0, 0 });
		visitTime[0][0] = 0;

		while (!pq.empty()) {
			auto [ct, cr, cc] = pq.top(); pq.pop();
			if (cr == R - 1 && cc == C - 1) break;

			for (const auto& [dr, dc] : dirs) {
				int nt = ct + 1, nr = cr + dr, nc = cc + dc;

				if (nr >= 0 && nr < R && nc >= 0 && nc < C && visitTime[nr][nc] == -1) {
					// move around to adj grid and back later
					if (nt < grid[nr][nc]) nt = grid[nr][nc] + (grid[nr][nc] - nt) % 2;
					pq.push({ nt, nr, nc });
					visitTime[nr][nc] = nt;
				}
			}
		}
		return visitTime[R - 1][C - 1];
	}
};
// @lc code=end
