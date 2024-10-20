/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
class Solution {
public:
	bool parseBoolExpr(string expression) {
		stack<char> st;

		for (const auto& ch : expression) {
			if (ch == ')') {
				vector<int> eval(2);	// 0 - f, 1 - t

				while (!st.empty() && st.top() != '(') {
					eval[st.top() == 't' ? 1 : 0]++;
					st.pop();
				}
				st.pop();

				char op = st.top(); st.pop();
				switch (op) {
					case '!' :
						st.push(eval[0] ? 't' : 'f');
						break;
					case '&' :
						st.push(eval[0] ? 'f' : 't');
						break;
					case '|' :
						st.push(eval[1] ? 't' : 'f');
						break;
				}
			} else if (ch != ',')
				st.push(ch);
		}
		return st.top() == 't';
	}
};
// @lc code=end
