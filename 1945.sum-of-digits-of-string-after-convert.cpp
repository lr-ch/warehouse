/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution {
public:
	int getLucky(string s, int k) {
		string convert;
		for (const auto& ch : s)
			convert += to_string((ch - 'a') + 1);

		int ans = 0;
		while (k--) {
			ans = 0;
			for (const auto& ch : convert)
				ans += (ch - '0');
			convert = to_string(ans);
		}

		return ans;
	}
};
// @lc code=end
