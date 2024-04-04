/*
 * @lc app=leetcode id=1614 lang=cpp
 * @lcpr version=30121
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
	int maxDepth(string s) {
		int depth = 0, bracket = 0;
		for (const auto& ch : s) {
			if (ch == '(') bracket++;
			if (ch == ')') bracket--;
			depth = max(depth, bracket);
		}
		return depth;
	}
};
// @lc code=end
