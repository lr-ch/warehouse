/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
class Solution {
public:
	bool canMakeSubsequence(string str1, string str2) {
		int curr = 0, count = 0;

		auto cyclic = [](const char& ch) -> char {
			return (ch != 'z' ? ch + 1 : 'a');
		};

		for (const auto& ch2 : str2) {
			while (curr < str1.length()) {
				char ch1 = str1[curr++];
				if (ch1 == ch2 || cyclic(ch1) == ch2) {
					count++;
					break;
				}
			}
		}
		return count == str2.length();
	}
};
// @lc code=end
