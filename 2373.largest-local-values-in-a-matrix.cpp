/*
 * @lc app=leetcode id=2373 lang=cpp
 * @lcpr version=30201
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		vector<vector<int>> ret(grid.size() - 2, vector<int>(grid.size() - 2, 0));

		for (int i = 0; i < grid.size() - 2; i++)
			for (int j = 0; j < grid.size() - 2; j++) {
				auto localMax = [&](const auto& i, const auto& j)->int {
					int maxi = INT_MIN;
					for (int r = i; r < i + 3; r++)
						for (int c = j; c < j + 3; c++)
							maxi = max(maxi, grid[r][c]);
					return maxi;
				};
				ret[i][j] = localMax(i, j);
			}

		return ret;
	}
};
// @lc code=end
