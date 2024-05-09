/*
 * @lc app=leetcode id=3075 lang=cpp
 * @lcpr version=30201
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start
class Solution {
public:
	long long maximumHappinessSum(vector<int>& happiness, int k) {
		sort(happiness.begin(), happiness.end(), greater<int>());
		long long ans = 0;
		for (int i = 0; i < k; i++)
			ans += max(0, happiness[i] - i);

		return ans;
	}
};
// @lc code=end
