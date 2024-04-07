/*
 * @lc app=leetcode id=678 lang=cpp
 * @lcpr version=30121
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
	bool checkValidString(string s) {
		stack<int> stars, left;     // indices of stars and left bracket

		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
				case '(':
					left.push(i);
					break;
				case '*':
					stars.push(i);
					break;
				case ')':
					if (left.empty()) {
						if (!stars.empty())
							stars.pop();	// consume a star
						else
							return false;	// no left bracket, no stars
					} else
						left.pop();			// consume a left bracket
					break;
			}
		}

		// now check remaining left brackets
		while (!left.empty())
			// left brackets should always go before stars
			if (!stars.empty() && left.top() < stars.top()) {
				left.pop();
				stars.pop();
			} else
				return false;

		return true;
	}
};
// @lc code=end
