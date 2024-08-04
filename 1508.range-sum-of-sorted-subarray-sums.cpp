/*
 * @lc app=leetcode id=1508 lang=cpp
 * @lcpr version=30204
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution {
	static constexpr int MOD = 1e9 + 7;
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		vector<int> countSub;
		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				countSub.push_back(sum);
			}
		}
		sort(countSub.begin(), countSub.end());

		long long ans = accumulate(countSub.begin() + left - 1, countSub.begin() + right, 0LL);

		return ans % MOD;
	}
};
// @lc code=end
