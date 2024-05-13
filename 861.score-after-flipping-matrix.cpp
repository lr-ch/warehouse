/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
	int matrixScore(vector<vector<int>>& grid) {
		/*
		 * Rule#1 - for each row, flip if there is leading zero
		 * Rule#2 - for each column, flip if the amount of '0' more than '1',
		 *          except for column#0 for avoid of leading 0
		 */
		int R = grid.size(), C = grid[0].size();
		vector<int> counter(grid[0].size(), 0);     // count '1' for each column

		for (int r = 0; r < R; r++) {
			// flip row if leading zero
			if (grid[r][0] == 0)
				for_each(grid[r].begin(), grid[r].end(), [](auto& i) { i = ~i & 1; });

			// count '1' for each column in this row
			for (int c = 1; c < C; c++)
				counter[c] += grid[r][c];
		}

		// flip column if the amount of '0' more than '1'
		for (int c = 1; c < C; c++)
			if (counter[c] < R - counter[c])
				for_each(grid.begin(), grid.end(), [&](auto& v) { v[c] = ~v[c] & 1; });

		int ans = 0;
		for_each(grid.begin(), grid.end(), [&](const auto& v) {
			int n = 0;
			for (int i = 0; i < v.size(); i++)
				n = n * 2 + v[i];
			ans += n;
		});

		return ans;
	}
};
// @lc code=end
