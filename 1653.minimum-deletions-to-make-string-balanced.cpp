/*
 * @lc app=leetcode id=1653 lang=cpp
 * @lcpr version=30204
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution {
public:
	int minimumDeletions(string s) {
		vector<int> count_a(s.length());
		vector<int> count_b(s.length());

		count_b.front() = (s.front() == 'b');
		for (int i = 1; i < s.length(); i++)
			count_b[i] += (count_b[i - 1] + (s[i] == 'b'));

		count_a.back() = (s.back() == 'a');
		for (int i = s.length() - 2; i >= 0; i--)
			count_a[i] += (count_a[i + 1] + (s[i] == 'a'));

		int ans = s.length();
		for (int i = 0; i < s.length(); i++)
			ans = min(ans, count_a[i] + count_b[i]);

		return ans - 1;
	}
};
// @lc code=end
