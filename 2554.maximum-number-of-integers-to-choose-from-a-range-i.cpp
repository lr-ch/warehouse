/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
class Solution {
public:
	int maxCount(vector<int>& banned, int n, int maxSum) {
		unordered_set<int> bs(banned.begin(), banned.end());

		int ret = 0, sum = 0;
		for (int curr = 1; curr <= n; curr++) {
			// whether curr is banned
			if (bs.count(curr)) continue;

			sum += curr;
			if (maxSum < sum) return ret;

			ret++;
		}
		return ret;
	}
};
// @lc code=end
