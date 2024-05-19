/*
 * @lc app=leetcode id=3068 lang=cpp
 * @lcpr version=30202
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
class Solution {
public:
	/*
	 *  1. For any two nodes in a tree, there is always a path to connect them
	 *  2. Any nodes between two nodes can be xor-ed twice to restore their original values
	 */
	long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
		vector<int> xork;
		for (const auto& n : nums)
			xork.push_back((n ^ k) - n);
		sort(xork.begin(), xork.end(), greater<int>());

		long long max_xor = 0, total_xor = 0;
		for (int i = 0; i + 1 < xork.size(); i += 2) {  // pick two nodes each time
			total_xor += (xork[i] + xork[i + 1]);
			max_xor = max(max_xor, total_xor);
		}

		return max_xor + accumulate(nums.begin(), nums.end(), 0LL);
	}
};
// @lc code=end
