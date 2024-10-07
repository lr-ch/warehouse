/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
class Solution {
public:
	int minLength(string s) {
		stack<char> st;

		for (const auto& ch : s) {
			if (!st.empty() &&
				(
					(ch == 'B' && st.top() == 'A') ||
					(ch == 'D' && st.top() == 'C')
				)
			) {
				st.pop();
			} else
				st.push(ch);
		}
		return st.size();
	}
};
// @lc code=end
