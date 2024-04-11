/*
 * @lc app=leetcode id=402 lang=cpp
 * @lcpr version=30122
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> digits;

		for (const auto& n : num) {
			while (!digits.empty() && k > 0 && digits.back() > n) {
				digits.pop_back();
				k--;
			}
			digits.push_back(n);
		}

		// handle remaining k digits
		if (k > 0)
			digits.erase(digits.end() - k, digits.end());

		// construct answer
		string ans;
		bool leading_zero = (digits[0] == '0');
		for (const auto& d : digits) {
			if (d != '0') leading_zero = false;
			if (leading_zero) continue;
			ans += d;
		}

		return ans.empty() ? "0" : ans;
	}
};
// @lc code=end
