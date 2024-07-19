/*
 * @lc app=leetcode id=1380 lang=cpp
 * @lcpr version=30204
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
	vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		vector<int> mini;
		for (const auto& v : matrix)
			mini.push_back(*min_element(v.begin(), v.end()));

		vector<int> maxi;
		for (int c = 0; c < matrix[0].size(); c++) {
			int m = INT_MIN;
			for (int r = 0; r < matrix.size(); r++)
				m = max(m, matrix[r][c]);
			maxi.push_back(m);
		}

		vector<int> lucky;
		for (int r = 0; r < matrix.size(); r++)
			for (int c = 0; c < matrix[0].size(); c++)
				if (matrix[r][c] == mini[r] && matrix[r][c] == maxi[c])
					lucky.push_back(matrix[r][c]);

		return lucky;
	}
};
// @lc code=end
