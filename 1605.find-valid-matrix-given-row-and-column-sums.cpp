/*
 * @lc app=leetcode id=1605 lang=cpp
 * @lcpr version=30204
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int R = rowSum.size(), C = colSum.size();
		vector<vector<int>> ans(R, vector<int>(C));

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				ans[r][c] = min(rowSum[r], colSum[c]);

				rowSum[r] -= ans[r][c];
				colSum[c] -= ans[r][c];
			}
		}

		return ans;
	}
};
// @lc code=end
