/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
class Solution {
public:
	long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
		sort(robot.begin(), robot.end());
		sort(factory.begin(), factory.end());

		// duplicate factory's position by its limit
		vector<int> factoryPos;
		for_each(factory.begin(), factory.end(), [&](const vector<int>& f) {
			for (int i = 0; i < f[1]; i++) factoryPos.push_back(f[0]);
		});

		// dp[i][j] = minimum distance traveled from ith robot to jth factory
		vector<vector<long long>> dp(
									robot.size() + 1,
									vector<long long>(factoryPos.size() + 1)
								);
		// init base case
		for (int i = 0; i < robot.size(); i++)
			dp[i][factoryPos.size()] = 1e12;		// no more factories

		for (int i = robot.size() - 1; i >= 0; i--)
			for (int j = factoryPos.size() - 1; j >= 0; j--)
				dp[i][j] = min(
							// robot[i] goes to factory[j]
							abs(robot[i] - factoryPos[j]) + dp[i + 1][j + 1],
							// robot[i] skip this factory to next(previous) factory
							dp[i][j + 1]
						);
		return dp[0][0];
	}
};
// @lc code=end
