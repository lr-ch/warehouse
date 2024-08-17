/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int ans = INT_MIN, curr = values[0];

		// values[i] + i + values[j] - j
		for (int i = 1; i < values.size(); i++) {
			ans = max(ans, curr + values[i] - i);
			curr = max(curr, values[i] + i);
		}
		return ans;
	}
};
// @lc code=end
