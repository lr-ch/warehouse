/*
 * @lc app=leetcode id=1992 lang=cpp
 * @lcpr version=30122
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		int R = land.size(), C = land[0].size();
		vector<vector<int>> ans;

		for (int r1 = 0; r1 < R; r1++) {
			for (int c1 = 0; c1 < C; c1++) {
				if (land[r1][c1] == 0) continue;

				int r2, c2;
				for (r2 = r1; r2 < R && land[r2][c1]; r2++)
					for (c2 = c1; c2 < C && land[r2][c2]; c2++)
						land[r2][c2] = 0;	// mark as visited

				ans.push_back({r1, c1, r2 - 1, c2 - 1});
			}
		}

		return ans;
	}
};
// @lc code=end
