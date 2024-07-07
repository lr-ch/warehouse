/*
 * @lc app=leetcode id=1518 lang=cpp
 * @lcpr version=30204
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
	int dfs(int fullBottles, int totalBottles, int numExchange) {
		if (totalBottles < numExchange) return fullBottles;
		return fullBottles + dfs(
					totalBottles / numExchange,									// water bottles
					totalBottles / numExchange + totalBottles % numExchange,	// water bottles + empty bottles
					numExchange);
	}

public:
	int numWaterBottles(int numBottles, int numExchange) {
		return dfs(numBottles, numBottles, numExchange);
	}
};
// @lc code=end
