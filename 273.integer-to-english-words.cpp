/*
 * @lc app=leetcode id=273 lang=cpp
 * @lcpr version=30204
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
	string convert(int n) {
		if (n == 0) return "";

		// e.g. 10 -> StrU20[9]
		if (n < 20) return StrU20[n - 1] + " ";

		// e.g. 99 -> StrU100[7] + " " + StrU20[8] + " "
		if (n < 100) return StrU100[n / 10 - 2] + convert(n % 10);

		for (int i = 0; i < OverH.size(); i++)
			if (n >= OverH[i])
				return convert(n / OverH[i]) + StrH2M[i] + convert(n % OverH[i]);

		return "NaN";
	}

	const array<string, 19> StrU20 = {{
								"One",     "Two",       "Three",    "Four",     "Five",
								"Six",     "Seven",     "Eight",    "Nine",     "Ten",
								"Eleven",  "Twelve",    "Thirteen", "Fourteen", "Fifteen",
								"Sixteen", "Seventeen", "Eighteen", "Nineteen" }};
	const array<string, 8> StrU100 = {{
								"Twenty ", "Thirty ",  "Forty ",  "Fifty ",
								"Sixty ",  "Seventy ", "Eighty ", "Ninety " }};
	const array<string, 4> StrH2M = {{ "Billion ", "Million ", "Thousand ", "Hundred " }};
	const array<int, 4> OverH = {{ (int)1e9, (int)1e6, (int)1e3, 100 }};
public:
	string numberToWords(int num) {
		if (num == 0) return "Zero";

		string ans = convert(num);

		// trim off trailing spaces
		while (ans.back() == ' ') ans.pop_back();
		return ans;
	}
};
// @lc code=end
