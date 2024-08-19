/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
	/*
	 * minSteps(1) = 0, minSteps(2) = 2, minSteps(3) = 2, minSteps(4) = 4, minSteps(5) = 5
	 *
	 *  6 = 2 * 3 -> 6 / 2 + 3 -> minSteps(2) + 3 = 5
	 *         or => 6 / 3 + 2 -> minSteps(3) + 2 = 5
	 */
	int minSteps(int n) {
		if (n == 1) return 0;

		int res = n;
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				res = min(res, minSteps(n / i) + i);

		return res;
	}
};
// @lc code=end

