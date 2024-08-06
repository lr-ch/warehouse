/*
 * @lc app=leetcode id=3016 lang=cpp
 * @lcpr version=30204
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
class Solution {
public:
	int minimumPushes(string word) {
		vector<int> freq(26);
		for (const auto& ch : word) freq[ch - 'a']++;
		sort(freq.begin(), freq.end(), greater<>());

		int count = 0, ans = 0;
		for (const auto& f : freq) {
			if (f != 0) {
				// assign a number to this character and count times of pushes
				ans += (count / 8 + 1) * f;
				// increase assign times
				count++;
			}
		}
		return ans;
	}
};
// @lc code=end
