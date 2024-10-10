/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution {
public:
	int maxWidthRamp(vector<int>& nums) {
		stack<int> indices;

		// create a stack with nums' indices in increasing order of values
		// e.g. nums	= [6,0,8,2,1,5]
		//      indices	= [0,1]
		for (auto i = 0; i < nums.size(); i++)
			if (indices.empty() || nums[indices.top()] > nums[i])
				indices.push(i);

		int ramp_width = 0;
		for (int i = nums.size() - 1; i >= 0; i--)
			// e.g. nums		= [6,0,8,2,1,5]
			//      indices		= [0,1]
			//      ramp_width  : nums[5] = 5 >= nums[indices.top() => 1] = 0
			//						=> 5 - 1 = 4
			while (!indices.empty() && nums[i] >= nums[indices.top()]) {
				ramp_width = max(ramp_width, i - indices.top());
				indices.pop();
			}

		return ramp_width;
	}
};
// @lc code=end
