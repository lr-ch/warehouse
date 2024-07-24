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

		sort(nums.begin(), nums.end(), [&](const auto& a, const auto& b) {
			return conv(a) < conv(b);
		});
		return nums;
	}
};
// @lc code=end
