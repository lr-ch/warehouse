/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		int left = 1, right = *max_element(nums.begin(), nums.end());

		while (left < right) {
			// assume mid is the penalty (maximun number) after maxOps
			int mid = left + (right - left) / 2;

			// calculate total ops needed to split each num into mid
			int ops = 0;
			for_each(nums.begin(), nums.end(), [&mid, &ops](const auto& n) {
				ops += (n - 1) / mid;
			});

			if (ops <= maxOperations)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};
// @lc code=end
