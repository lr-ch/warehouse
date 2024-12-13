/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */

// @lc code=start
class Solution {
public:
	vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		vector<int> preSum(nums.size(), 0);
		for (int i = 1; i < nums.size(); i++) {
			preSum[i] = preSum[i - 1];
			if (nums[i] % 2 == nums[i - 1] % 2)
				preSum[i]++;
		}

		vector<bool> ans;
		for (const auto& q : queries) {
			int start = q[0], end = q[1],
				count = preSum[end] - preSum[start];
				ans.push_back(count == 0);
		}
		return ans;
	}
};
// @lc code=end
