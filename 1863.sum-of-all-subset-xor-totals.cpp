/*
 * @lc app=leetcode id=1863 lang=cpp
 * @lcpr version=30202
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
	void bt(vector<int>& nums, int index, int xor_value) {
		if (index == nums.size()) {
			ans += xor_value;
			return;
		}

		// xor this num
		bt(nums, index + 1, xor_value ^ nums[index]);

		// not xor this num
		bt(nums, index + 1, xor_value);
	}

	int ans = 0;
public:
	int subsetXORSum(vector<int>& nums) {
		bt(nums, 0, 0);
		return ans;
	}
};
// @lc code=end
