/*
 * @lc app=leetcode id=719 lang=cpp
 * @lcpr version=30204
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		vector<int> freq(nums.back() + 1);
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				freq[nums[j] - nums[i]]++;

		int count = 0;
		for (int i = 0; i < freq.size(); i++) {
			count += freq[i];
			if (count >= k)
				return i;
		}
		return 0;
	}
};
// @lc code=end
