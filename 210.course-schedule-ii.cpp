/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> adjs(numCourses);
		vector<int> ind(numCourses);
		for (const auto& p : prerequisites) {
			int from = p[1], to = p[0];
			adjs[from].push_back(to);
			ind[to]++;
		}

		queue<int> q;
		for (int i = 0; i < ind.size(); i++) if (ind[i] == 0) q.push(i);

		vector<int> ans;
		while (!q.empty()) {
			int from = q.front(); q.pop();
			ans.push_back(from);
			for (const auto& to : adjs[from]) {
				ind[to]--;

				if (ind[to] == 0) q.push(to);
			}
		}

		if (ans.size() == numCourses) return ans;
		return {};
	}
};
// @lc code=end
