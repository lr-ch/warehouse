/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {
public:
	long long maxMatrixSum(vector<vector<int>>& matrix) {
		long long ans = 0;
		int minimun = INT_MAX, count = 0;

		for (const auto& row : matrix) {
			for (const auto& col : row) {
				ans += abs(col);
				minimun = min(minimun, abs(col));
				count += (col < 0 ? 1 : 0);
			}
		}

		return (count % 2 ? ans - 2 * minimun : ans);
	}
};
// @lc code=end
