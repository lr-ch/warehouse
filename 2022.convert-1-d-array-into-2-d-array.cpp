/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (m * n != original.size()) return {};

		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			res[i] = vector<int>(original.begin() + i * n, original.begin() + i * n + n);
		return res;
	}
};
// @lc code=end

