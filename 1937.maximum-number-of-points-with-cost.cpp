/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		int R = points.size(), C = points[0].size();
		vector<vector<long long>> dp(R, vector<long long>(C, INT_MIN));

		// init dp[0]
		for (int c = 0; c < C; ++c) dp[0][c] = points[0][c];

		// start from row#1
		for (int r = 1; r < R; ++r) {
			// ref. [1014] Best Sightseeing Pair
			//
			//    values[i][j] + dp[i - 1][k] - abs(j - k)
			// -> For j >= k, k = 0, 1, 2, ..., j
			//    values[i][j] - j + dp[i - 1][k] + k
			//
			// -> For j < k, k = j + 1, J = 2, ..., C - 1
			//    values[i][j] + j + dp[i - 1][k] - k
			long long curr_max = INT_MIN;

			for (int c = 0; c < C; ++c) {
				curr_max = max(curr_max, dp[r - 1][c] + c);
				dp[r][c] = max(dp[r][c], points[r][c] - c + curr_max);
			}

			curr_max = INT_MIN;
			for (int c = C - 1; c >= 0; --c) {
				curr_max = max(curr_max, dp[r - 1][c] - c);
				dp[r][c] = max(dp[r][c], points[r][c] + c + curr_max);
			}
		}

		return *max_element(dp.back().begin(), dp.back().end());
	}
};
// @lc code=end
