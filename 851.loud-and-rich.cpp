/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start
class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();

		vector<vector<int>> adjs(n);		// graph of rich -> poor
		vector<int> inds(n);				// indegree of poor node
		for (const auto& r : richer) {
			int rich = r[0], poor = r[1];
			adjs[rich].push_back(poor);
			inds[poor]++;
		}

		queue<int> q;
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if (inds[i] == 0) q.push(i);	// start from richest node
			ans[i] = i;						// init answer with each node#
		}

		while (!q.empty()) {
			int rich = q.front(); q.pop();

			for (const auto& poor : adjs[rich]) {
				inds[poor]--;

				if (quiet[ans[poor]] > quiet[ans[rich]]) ans[poor] = ans[rich];
				if (inds[poor] == 0) q.push(poor);
			}
		}

		return ans;
	}
};
// @lc code=end
