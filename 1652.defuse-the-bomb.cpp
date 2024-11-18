/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		if (k == 0) return vector<int>(code.size(), 0);

		vector<int> ans(code.size());
		for (int i = 0; i < code.size(); ++i) {
			if (k > 0) {
				for (int j = i + 1; j < i + k + 1; j++)
					ans[i] += code[j % code.size()];
			} else {
				for (int j = i - abs(k); j < i; j++)
					ans[i] += code[(j + code.size()) % code.size()];
			}
		}

		return ans;
	}
};
// @lc code=end
