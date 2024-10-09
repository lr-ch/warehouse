/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
	int minAddToMakeValid(string s) {
		stack<char> st;
		int res = 0;

		for (const auto& ch : s) {
			if (ch == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
					res -= 2;
				}
			} else
				st.push(ch);

			res++;
		}

		return res;
	}
};
// @lc code=end

