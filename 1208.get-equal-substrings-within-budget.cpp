/*
 * @lc app=leetcode id=1208 lang=cpp
 * @lcpr version=30202
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int left = 0, right = 0, ans = INT_MIN;
		while (right < s.length()) {
			// consume budget
			maxCost -= abs(s[right] - t[right]);
			right++;
			// resume budget
			while (maxCost < 0) {
				maxCost += abs(s[left] - t[left]);
				left++;
			}
			ans = max(ans, right - left);
		}
		return ans;
	}
};
// @lc code=end
