/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int res = 0;
		for (int r = 0; r < matrix.size(); r++) {
			for (int c = 0; c < matrix[0].size(); c++) {
				if (matrix[r][c] != 0 && r > 0 && c > 0)
					matrix[r][c] = min({matrix[r - 1][c], matrix[r][c - 1], matrix[r - 1][c - 1]}) + 1;
				res += matrix[r][c];
			}
		}
		return res;
	}
};
// @lc code=end
