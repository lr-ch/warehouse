/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

// @lc code=start
class Solution {
public:
	vector<int> resultsArray(vector<int>& nums, int k) {
		if (k == 1) return nums;

	//	vector<int> ans;
		vector<int> ans(nums.size() - k + 1);
		int left = 0, right = 0, ascendings = 0;
		while (++right < nums.size()) {
			// count ascendings
			if (nums[right] - nums[right - 1] == 1) ascendings++;
			else ascendings = 0;

			// fill up the window
			if (right - left != k - 1) continue;

			// if the window is good, add the power of the subarray to answer
		//	if (ascendings == k - 1) ans.push_back(nums[right]);
		//	else ans.push_back(-1);
			if (ascendings == k - 1) ans[right - k + 1] = nums[right];
			else ans[right - k + 1] = -1;

			// slide window to right, but also consider substract of ascendings if
			// the window is already good
			if (ascendings == k - 1 && nums[right] - nums[left] == k - 1) ascendings--;
			left++;
		}
		return ans;
	}
};
// @lc code=end
