/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
class Solution {
public:
	int maximumBeauty(vector<int>& nums, int k) {
		int maxVal = *max_element(nums.begin(), nums.end());

		vector<int> count(maxVal + 1, 0);
		for_each(nums.begin(), nums.end(), [&](auto& n) {
			count[max(n - k, 0)]++;
			if (n + k + 1 <= maxVal) count[n + k + 1]--;
		});

		int curr = 0, ans = 0;
		for_each(count.begin(), count.end(), [&](auto& n) {
			curr += n;
			ans = max(ans, curr);
		});
		return ans;
	}
};
// @lc code=end
