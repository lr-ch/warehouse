/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
public:
	int specialArray(vector<int>& nums) {
		int x = 0;
		for (int i = 0; i <= nums.size(); i++) {
			x = count_if(nums.begin(), nums.end(), [&](const auto& val) {
				return val >= i;
			});
			if (i == x) return x;
		}
		return -1;
	}
};
// @lc code=end
