/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int maxVal = pow(2, maximumBit) - 1;	// the max value can reach with maximumBit bits

		vector<int> res(nums.size());

		int lastXor = 0;
		for (int i = 0; i < nums.size(); i++) {
			lastXor ^= nums[i];
			res[nums.size() - i - 1] = lastXor ^ maxVal;
		}
		return res;
	}
};
// @lc code=end
