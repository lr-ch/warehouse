/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 */

// @lc code=start
class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		vector<vector<int>> adjs(n);
		for (int i = 0; i < n; i++) adjs[i].push_back(i + 1);

		auto bfs = [&adjs, &n]() -> int {
			vector<bool> visited(n, false);
			queue<int> q;
			q.push(0);		// start from node#0

			int steps = 0;
			while (!q.empty()) {
				int qsize = q.size();
				while (qsize--) {
					auto curr = q.front(); q.pop();
					if (curr == n - 1) return steps;
					visited[curr] = true;
					for (const auto& next : adjs[curr]) {
						if (!visited[next]) q.push(next);
					}
				}
				steps++;
			}
			return -1;		// should not come here
		};

		vector<int> ans(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			adjs[queries[i][0]].push_back(queries[i][1]);
			ans[i] = bfs();
		}
		return ans;
	}
};
// @lc code=end
