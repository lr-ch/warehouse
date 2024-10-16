/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		string r;
		int len = a + b + c, A = 0, B = 0, C = 0;

		/*
		 * rule1. pick the most char first, if it appears less than 2 times
		 * rule2. pick the last char if the other two appears 2 times already
		 */
		for (int i = 0; i < len; i++) {
			if (
				(max({a, b, c}) == a && A < 2) ||
				(a > 0 && B == 2) ||
				(a > 0 && C == 2)
			) {
				r += 'a';
				a--;
				A++;
				B = 0;
				C = 0;
			} else if (
				(max({a, b, c}) == b && B < 2) ||
				(b > 0 && A == 2) ||
				(b > 0 && C == 2)
			) {
				r += 'b';
				b--;
				B++;
				A = 0;
				C = 0;
			} else if (
				(max({a, b, c}) == c && C < 2) ||
				(c > 0 && A == 2) ||
				(c > 0 && B == 2)
			) {
				r += 'c';
				c--;
				C++;
				A = 0;
				B = 0;
			}
		}
		return r;
	}
};
// @lc code=end

