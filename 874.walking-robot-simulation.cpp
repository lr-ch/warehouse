/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
	array<pair<int, int>, 4> dirs = {{
								{  0,  1 },		// N
								{  1,  0 },		// E
								{  0, -1 },		// S
								{ -1,  0 }		// W
							}};
	int compass = 0;							// initial to N
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		set<pair<int, int>> obs;
		for_each(obstacles.begin(), obstacles.end(), [&](const auto& o) {
			obs.insert({ o[0], o[1]});
		});

		int ans = INT_MIN, x = 0, y = 0;
		for (auto cmd : commands) {
			switch (cmd) {
				case -2 :	// to left
					compass--;
					if (compass < 0) compass = 3;	// to west
					break;
				case -1 :	// to right
					compass++;
					if (compass > 3) compass = 0;	// to north
					break;
				default :	// forward
				{
					int nx = x, ny = y;
					while (cmd--) {
						auto [dx, dy] = dirs[compass];
						if (obs.count({ nx + dx, ny + dy })) break;
						nx += dx;
						ny += dy;
					}
					x = nx; y = ny;
					ans = max(ans, x * x + y * y);
				}
			}
		}
		return ans;
	}
};
// @lc code=end
