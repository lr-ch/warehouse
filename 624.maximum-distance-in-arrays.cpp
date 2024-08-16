/*
 * @lc app=leetcode id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] Maximum Distance in Arrays
 */

// @lc code=start
class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int maxi = INT_MIN / 2, mini = INT_MAX / 2, res = 0;

		for (const auto& a : arrays) {
			res = max({res, a.back() - mini, maxi - a.front()});

			maxi = max(maxi, a.back());
			mini = min(mini, a.front());
		}

		return res;
	}
};
// @lc code=end
