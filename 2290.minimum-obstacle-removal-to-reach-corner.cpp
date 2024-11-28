/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
class Solution {
	const array<pair<int, int>, 4> dirs = {{
										{ 0, 1 }, { 1, 0 }, { 0, -1 }, {-1, 0 }
									}};
public:
	int minimumObstacles(vector<vector<int>>& grid) {
		int R = grid.size(), C = grid[0].size();

		// a memo to record least obstacles removed count
		vector<vector<int>> obsCount(R, vector<int>(C, -1));

		deque<tuple<int, int, int>> dq;		// (row, col, count of obstacles removed)
		dq.push_front({ 0, 0, 0 });			// start from (0, 0)
		obsCount[0][0] = 0;

		while (!dq.empty()) {
			auto [cr, cc, obs] = dq.front(); dq.pop_front();

			// search for next grid
			for (const auto& [dr, dc] : dirs) {
				int nr = cr + dr, nc = cc + dc;

				if (nr >= 0 && nr < R && nc >= 0 && nc < C && obsCount[nr][nc] == -1) {
					if (grid[nr][nc] == 0) {
						// if the grid has no obstacle, keep current obstacle count
						// and keep searching for next grid in higher priority
						obsCount[nr][nc] = obs;
						dq.push_front({ nr, nc, obs });
					} else {
						// if the grid has obstacle, plus current obstacle count by 1
						// and insert into queue in lower priority
						obsCount[nr][nc] = obs + 1;
						dq.push_back({ nr, nc, obs + 1 });
					}
				} else {
					// if a grid can be reached by removing obsCount[nr][nc] obstacles,
					// no need to visit it again...
				}
			}
		}
		return obsCount[R - 1][C - 1];
	}
};
// @lc code=end
