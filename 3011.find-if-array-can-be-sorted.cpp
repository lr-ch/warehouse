/*
 * @lc app=leetcode id=3011 lang=cpp
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start
class Solution {
public:
	bool canSortArray(vector<int>& nums) {
		int last_max = 0, current_max = 0, bits = 0;

		for (int i = 0; i < nums.size(); ++i) {
			bitset<32> current(nums[i]);

			// check if this value and the previous value are in the same group
			if (current.count() != bits) {
				// if not, create a new group
				bits = current.count();

				// update the maximum value in previous group and current group
				last_max = current_max;
				current_max = nums[i];
			}

			// if the previous group'smaximum value is greater than value in current group
			if (last_max > nums[i]) return false;

			// update the maximum value in current group
			current_max = max(current_max, nums[i]);
		}
		return true;
	}
};
// @lc code=end
