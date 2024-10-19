/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
class Solution {
public:
	char findKthBit(int n, int k) {
		string s = "0";

		for (int i = 1; i < n && s.length() < k; i++) {
			s += '1';

			string tmp = s;
			for (int j = tmp.length() - 2; j >= 0; j--)
				s += (tmp[j] == '0' ? '1' : '0');
		}
		return s[k - 1];
	}
};
// @lc code=end

