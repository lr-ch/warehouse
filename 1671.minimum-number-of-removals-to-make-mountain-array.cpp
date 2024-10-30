/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
class Solution {
public:
	int minimumMountainRemovals(vector<int>& nums) {
		/*
		 * ref. [300] Longest Increasing Subsequence
		 */

		// Approach 1: O(N^2), use DP
		// dp[i] -> the length of LIS ending at nums[i]
		/*
		 * Accepted
		 *  - 90/90 cases passed (79 ms)
		 *  - Your runtime beats 24.24 % of cpp submissions
		 *  - Your memory usage beats 67.26 % of cpp submissions (14.9 MB)
		 */
		auto lis = [](auto start, auto end, vector<int>& dp) {
			for (int i = 0; start + i != end; i++)
				for (int j = 0; j < i; j++)
					if (*(start + i) > *(start + j))
						dp[i] = max(dp[i], dp[j] + 1);
		};

		// Approach 2: O(NLOG(N)), use an ascending number Stack
		/*
		 * Accepted
		 *  - 90/90 cases passed (1 ms)
		 *  - Your runtime beats 95.45 % of cpp submissions
		 *  - Your memory usage beats 31.84 % of cpp submissions (15.17 MB)
		 */
		auto lis2 = [](auto start, auto end, vector<int>& dp) {
			vector<int> stack;
			for (int i = 0; start + i != end; i++) {
				if (stack.empty() || stack.back() < *(start + i)) {
					stack.push_back(*(start + i));	// a larger value appended, LIS length increased!!
					dp[i] = stack.size();
				} else {
					auto iter = lower_bound(stack.begin(), stack.end(), *(start + i));
					*iter = *(start + i);			// replace with lower value to help compose longer sequence
					dp[i] = iter - stack.begin() + 1;
				}
			}
		};

		vector<int> left(nums.size(), 1), right(nums.size(), 1);

		// count LIS from left to right at each position
	//	lis(nums.begin(), nums.end(), left);
		lis2(nums.begin(), nums.end(), left);

		// count LIS from right to left at each position
	//	lis(nums.rbegin(), nums.rend(), right);
		lis2(nums.rbegin(), nums.rend(), right);
		// the order is reversed
		reverse(right.begin(), right.end());

		int ans = 0;
		for (int peak = 0; peak < nums.size(); peak++)
			if (left[peak] > 1 && right[peak] > 1)
				ans = max(ans, left[peak] + right[peak] - 1);

		return nums.size() - ans;
	}
};
// @lc code=end
