/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
class Solution {
public:
	int longestSquareStreak(vector<int>& nums) {
		int maxi = *max_element(nums.begin(), nums.end());
		unordered_set<long> s(nums.begin(), nums.end());

		int ans = 0;
		for (int i = 2; i * i <= maxi; i++) {
			int streak = 0;
			long sq = i;			// in case sq * sq is overflow
			while (s.count(sq)) {
				streak++;
				sq *= sq;
			}
			ans = max(ans, streak);
		}

		return ans < 2 ? -1 : ans;
	}
};
// @lc code=end
