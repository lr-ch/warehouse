/*
 * @lc app=leetcode id=2045 lang=cpp
 * @lcpr version=30204
 *
 * [2045] Second Minimum Time to Reach Destination
 */

// @lc code=start
class Solution {
public:
	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		vector<vector<int>> adjs(n + 1);		// n starts from 1
		for (const auto& e : edges) {
			int from = e[0], to = e[1];
			adjs[from].push_back(to);
			adjs[to].push_back(from);
		}

		vector<pair<int, int>> visited(n + 1);	// (visited times, least reach time)
		visited[1] = { 1, 0 };

		queue<pair<int, int>> q;				// (current city, current time)
		q.push({ 1, 0 });

		while (!q.empty()) {
			auto [curr, curr_time] = q.front(); q.pop();
			int cycle = curr_time / change;
			int next_time = (cycle % 2)
								? (cycle + 1) * change + time	// red light cycle, wait for next cycle
								: curr_time + time;				// green light, instantly to next city

			for (const auto& next : adjs[curr]) {
				auto& [visits, least] = visited[next];

				if (visits < 2 && next_time > least ) {
					visits++;
					least = next_time;
					q.push({ next, next_time });

					if (next == n && visits == 2)
						return next_time;
				}
			}
		}
		return -1;
	}
};
// @lc code=end
