/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
	void dfs(vector<int>& nums, int index, int sum, int target) {
		if (index == nums.size()) {
			if (sum == target) ans++;
			return;
		}

		dfs(nums, index + 1, sum - nums[index], target);
		dfs(nums, index + 1, sum + nums[index], target);
	}

	int ans = 0;
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		dfs(nums, 0, 0, target);
		return ans;
	}
};
// @lc code=end
