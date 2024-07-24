/*
 * @lc app=leetcode id=2191 lang=cpp
 * @lcpr version=30204
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
class Solution {
public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		auto conv = [&](auto n)->int {
			int p = 0, res = 0;
			do {
				res += mapping[n % 10] * pow(10, p++);
				n /= 10;
			} while (n);
			return res;
		};

		vector<pair<int, int>> converted(nums.size());
		for (int i = 0; i < nums.size(); i++)
			converted[i] = { conv(nums[i]), i };

		sort(converted.begin(), converted.end());

		vector<int> ans(nums.size());
		for (int i = 0; i < nums.size(); i++)
			ans[i] = nums[converted[i].second];
		return ans;
	}
};
// @lc code=end
