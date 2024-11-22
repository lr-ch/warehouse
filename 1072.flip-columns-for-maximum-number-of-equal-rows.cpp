/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<string, int> patternsCounter;
		int res = 0;
		for_each(matrix.begin(), matrix.end(), [&patternsCounter, &res](const auto& row) {
			string pattern;
			for (int i = 0; i < row.size(); i++) {
				if (row[0] == row[i]) pattern += '1';
				else pattern += '0';
			}
			patternsCounter[pattern]++;
			res = max(res, patternsCounter[pattern]);
		});
		return res;
	}
};
// @lc code=end
