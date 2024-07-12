/*
 * @lc app=leetcode id=1717 lang=cpp
 * @lcpr version=30204
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
class Solution {
public:
	int maximumGain(string s, int x, int y) {
		// prefer "ab" (x points) or "ba" (y points)
		string str = (x > y) ? "ab" : "ba";
		int score1 = max(x, y), score2 = min(x, y);

		stack<char> st1, st2;
		int res = 0;
		for (const auto& ch : s) {
			if (!st1.empty() && st1.top() == str[0] && ch == str[1]) {
				st1.pop();
				res += score1;
			} else
				st1.push(ch);
		}

		while (!st1.empty()) {
			char ch = st1.top(); st1.pop();
			if (!st2.empty() && st2.top() == str[0] && ch == str[1]) {
				st2.pop();
				res += score2;
			} else
				st2.push(ch);
		}

		return res;
	}
};
// @lc code=end
