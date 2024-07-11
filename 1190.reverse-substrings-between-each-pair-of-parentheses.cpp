/*
 * @lc app=leetcode id=1190 lang=cpp
 * @lcpr version=30204
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class SolutionSim {
public:
	string reverseParentheses(string& s) {
		string ans;
		stack<int> indice;   // position of each '('
		for (const auto& ch : s) {
			switch (ch) {
				case '(' :
					indice.push(ans.length());
					break;
				case ')' :
					reverse(ans.begin() + indice.top(), ans.end());
					indice.pop();
					break;
				default :
					ans += ch;
					break;
			}
		}
		return ans;
	}
};

class SolutionOn {
public:
	string reverseParentheses(string& s) {
		string ans;
		stack<int> indice;				// position of each '('
		vector<int> pair(s.length());	// position of each '(', ')' pair
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
				case '(' :
					indice.push(i);
					break;
				case ')' :
					pair[i] = indice.top();
					pair[indice.top()] = i;
					indice.pop();
					break;
				default :
					break;
			}
		}

		// dir =  1 : left -> right
		// dir = -1 : right -> left
		for (int i = 0, dir = 1; i < s.length(); i += dir) {
			switch (s[i]) {
				case '(' :
				case ')' :
					i = pair[i];	// jump to next char at pair of '(' or ')'
					dir = -dir;		// reverse dir
					break;
				default :
					ans += s[i];
					break;
			}
		}
		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 38/38 cases passed (3 ms)
	 *  - Your runtime beats 49.64 % of cpp submissions
	 *  - Your memory usage beats 50.36 % of cpp submissions (7.8 MB)
	 */
	SolutionSim sim;

	/*
	 * Accepted
	 *  - 38/38 cases passed (3 ms)
	 *  - Your runtime beats 49.64 % of cpp submissions
	 *  - Your memory usage beats 52.67 % of cpp submissions (7.8 MB)
	 */
	SolutionOn oN;
public:
	string reverseParentheses(string& s) {
	//	return sim.reverseParentheses(s);
		return oN.reverseParentheses(s);
	}
};
// @lc code=end
