/*
 * @lc app=leetcode id=2678 lang=cpp
 * @lcpr version=30204
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
class Solution {
public:
	int countSeniors(vector<string>& details) {
		return count_if(details.begin(), details.end(), [](const string& d) {
			return ((d[11] - '0') * 10 + d[12] - '0') > 60;
		});
	}
};
// @lc code=end
