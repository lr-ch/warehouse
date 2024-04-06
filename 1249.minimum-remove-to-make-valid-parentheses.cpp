/*
 * @lc app=leetcode id=1249 lang=cpp
 * @lcpr version=30121
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string ans;
		stack<int> st;	// record indice of '('

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				st.push(i);
				continue;
			}

			if (s[i] == ')') {
				// validate the ')'
				if (st.empty()) s[i] = '?';
				else st.pop();
			}
		}

		// validate remain '('
		while (!st.empty()) {
			s[st.top()] = '?';
			st.pop();
		}

		for (const auto& ch : s)
			if (ch != '?') ans += ch;

		return ans;
	}
};
// @lc code=end
