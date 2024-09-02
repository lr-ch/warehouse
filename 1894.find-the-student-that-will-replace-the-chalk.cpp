/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution {
public:
	int chalkReplacer(vector<int>& chalk, int k) {
		vector<unsigned long> preSum(chalk.size());
		preSum[0] = chalk[0];
		for (int i = 1; i < chalk.size(); i++)
			preSum[i] = preSum[i- 1] + chalk[i];

		k %= preSum.back();

		for (int i = 0; i < preSum.size(); i++)
			if (preSum[i] > k) return i;

		return INT_MAX;
	}
};
// @lc code=end

