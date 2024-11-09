/*
 * @lc app=leetcode id=3133 lang=cpp
 *
 * [3133] Minimum Array End
 */

// @lc code=start
class Solution {
public:
	long long minEnd(int n, int x) {
		long long ans = x;

		for (; n > 1; n--)
			ans = (++ans | x);
		return ans;
	}
};
// @lc code=end
