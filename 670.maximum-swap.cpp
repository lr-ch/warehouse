/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
public:
	int maximumSwap(int num) {
		string s = to_string(num);
		int M = -1, c1 = -1, c2 = -1;

		for (int i = s.length() - 1; i >= 0; i--) {
			if (M == -1 || s[i] > s[M])
				M = i;		// keep track of maximun digit
			else if (s[i] < s[M]) {
				c1 = i;		// if smaller digit appears in front of M,
				c2 = M;		// we could swap this digit with digit M
			}
		}

		// only swap when smaller digit appears in front of maximun digit
		if (c1 < c2) swap(s[c1], s[c2]);

		return stoi(s);
	}
};
// @lc code=end

