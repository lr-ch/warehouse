/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

// @lc code=start
class Solution {
public:
	long long findScore(vector<int>& nums) {
		vector<pair<int, int>> table(nums.size());	// (num, index)
		for (int i = 0; i < nums.size(); i++)
			table[i] = { nums[i], i };
		sort(table.begin(), table.end());

		vector<bool> mark(nums.size(), false);
		long long ans = 0;

		for (int i = 0; i < nums.size(); i++) {
			auto [num, index] = table[i];
			if (!mark[index]) {
				ans += num;
				mark[index] = true;

				if (index - 1 >= 0) mark[index - 1] = true;
				if (index + 1 < nums.size()) mark[index + 1] = true;
			}
		}
		return ans;
	}
};
// @lc code=end
