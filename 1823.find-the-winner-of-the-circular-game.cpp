/*
 * @lc app=leetcode id=1823 lang=cpp
 * @lcpr version=30204
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
	int dfs(int n, int k) {
		if (n == 1) return 0;
		return (dfs(n - 1, k) + k) % n;
	}

public:
	int findTheWinner(int n, int k) {
		return dfs(n, k) + 1;
	}
};
// @lc code=end
