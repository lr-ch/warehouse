/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
class Solution {
public:
	int minSwaps(string s) {
		stack<char> st;
		int to_swap = 0;

		for (const auto& ch : s) {
			if (ch == '[') {
				st.push(ch);
				continue;
			}

			if (!st.empty())
				st.pop();
			else
				to_swap++;
		}
		return (to_swap + 1) / 2;
	}
};
// @lc code=end
