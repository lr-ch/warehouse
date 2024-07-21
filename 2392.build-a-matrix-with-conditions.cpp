/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */

// @lc code=start
class Solution {
	vector<int> topoSort(int k, vector<vector<int>>& conds) {
		unordered_map<int, vector<int>> adjs;
		vector<int> ind(k + 1);								// node# starts from 1
		for (const auto& v : conds) {
			int from = v[0], to = v[1];
			adjs[from].push_back(to);
			ind[to]++;
		}

		queue<int> q;
		for (int i = 1; i <= k; i++)
			if (ind[i] == 0) q.push(i);						// start from leaves

		vector<int> ans;
		while (!q.empty()) {
			int from = q.front(); q.pop();
			ans.push_back(from);

			for (const auto& to : adjs[from]) {
				ind[to]--;

				if (ind[to] == 0) q.push(to);
			}
		}
		return ans;
	}

public:
	vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		auto rowV = topoSort(k, rowConditions);
		auto colV = topoSort(k, colConditions);

		if (rowV.size() != k || colV.size() != k) return {};

		/*
		 * e.g.
		 *  rowV = { 1, 3, 2 }, colV = { 3, 2, 1 }
		 *
		 *           | 0 0 1 |
		 *  matrix = | 3 0 0 |
		 *           | 0 2 0 |
		 */
		vector<pair<int, int>> pos(k + 1);					// node# starts from 1
		for (int r = 0; r < rowV.size(); r++) pos[rowV[r]].first = r;
		for (int c = 0; c < colV.size(); c++) pos[colV[c]].second = c;

		vector<vector<int>> ret(k, vector<int>(k));
		for (int i = 1; i <= k; i++) {
			const auto& [r, c] = pos[i];
			ret[r][c] = i;
		}

		return ret;
	}
};
// @lc code=end
