/*
 * @lc app=leetcode id=1404 lang=cpp
 * @lcpr version=30202
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
class Solution {
public:
	int numSteps(string s) {
		reverse(s.begin(), s.end());
		int steps = 0;
		while (s != "1") {
			if (s[0] == '0') {
				s = s.substr(1, s.length() - 1);
				steps++;
			} else {
				bool carry = true;
				for (int i = 0; i < s.length(); i++) {
					if (!carry) break;
					if (s[i] == '1') {
						s[i] = '0';		// flip
						carry = true;
					} else {
						s[i] = '1';		// flip
						carry = false;
					}
				}
				if (carry) s += '1';
				steps++;
			}
		}
		return steps;
	}
};
// @lc code=end
