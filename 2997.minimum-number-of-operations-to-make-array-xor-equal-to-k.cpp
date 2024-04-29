/*
 * @lc app=leetcode id=2997 lang=cpp
 * @lcpr version=30122
 *
 * [2997] Minimum Number of Operations to Make Array XOR Equal to K
 */

// @lc code=start
class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		int xor_all = nums[0];
		for (int i = 1; i < nums.size(); i++)
			xor_all ^= nums[i];
		xor_all ^= k;

		int ans = 0;
		bitset<32> all_bits(xor_all);
		for (int i = 0; i < 32; i++)
			ans += (all_bits[i] == 1);
		return ans;
	}
};
// @lc code=end
