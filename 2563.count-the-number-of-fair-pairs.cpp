/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

// @lc code=start
class Solution {
public:
	long long countFairPairs(vector<int>& nums, int lower, int upper) {
		sort(nums.begin(), nums.end());

		long long count = 0;
		for (const auto& n : nums) {
			auto l = lower_bound(nums.begin(), nums.end(), lower - n) - nums.begin(),
				 u = upper_bound(nums.begin(), nums.end(), upper - n) - nums.begin();

			count += u - l;

			if (n >= lower - n && n <= upper - n) count--;
		}
		return count / 2;
	}
};
// @lc code=end
