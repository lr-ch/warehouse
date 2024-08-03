/*
 * @lc app=leetcode id=1460 lang=cpp
 * @lcpr version=30204
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		sort(target.begin(), target.end());
		sort(arr.begin(), arr.end());
		return target == arr;
	}
};
// @lc code=end
