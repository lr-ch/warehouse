/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution {
	void dfs(int cur, int n) {
		if (cur > n) return;

		ans.push_back(cur);
		for (int i = 0; i <= 9; ++i) {
			if (cur * 10 + i <= n)
				dfs(cur * 10 + i, n);
			else
				break;
		}
	}

	vector<int> ans;
public:
	vector<int> lexicalOrder(int n) {
		for (int i = 1; i <= 9; i++)
			dfs(i, n);
		return ans;
	}
};
// @lc code=end
