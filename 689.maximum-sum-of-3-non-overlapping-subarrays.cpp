/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> preSum(nums.size() + 1);
		for (int i = 0; i < nums.size(); i++)
			preSum[i + 1] = preSum[i] + nums[i];

		/*
		 *  Two tables to record the best start index with maximun sum
		 *  e.g. [7,13,20,19,19,2,10,1,1,19], k = 3
		 *     leftMax = [0 0 0 1 2 2 2 2 2 2]
		 *    rightMax = [2 2 2 3 4 7 7 7 0 0]
		 *
		 *  Note. The zeroes in front of leftMax at back of rightMax is because
		 *        we tabulate from index of [k] and [nums.size() - k]
		 */
		vector<int> leftMax(nums.size()), rightMax(nums.size());

		// tabulate the best start index from left most subarray
		int maxSum = preSum[k] - preSum[0];
		for (int i = k; i < nums.size(); i++) {
			int currSum = preSum[i + 1] - preSum[i - k + 1];
			if (currSum > maxSum) {
				maxSum = currSum;
				leftMax[i] = i - k + 1;
			} else
				leftMax[i] = leftMax[i - 1];
		}

		// tabulate the best start index from right most subarray
		rightMax[nums.size() - k] = nums.size() - k;
		maxSum = preSum[nums.size()] - preSum[nums.size() - k];
		for (int i = nums.size() - k - 1; i >= 0; i--) {
			int currSum = preSum[i + k] - preSum[i];
			if (currSum >= maxSum) {	// to keep index as lower as possible,
										// case of '=' should be in consideration
				maxSum = currSum;
				rightMax[i] = i;
			} else
				rightMax[i] = rightMax[i + 1];
		}

		// process the middle part
		maxSum = INT_MIN;
		vector<int> ans;
		for (int i = k; i <= nums.size() - 2 * k; i++) {
			int leftMaxId = leftMax[i - 1],
				rightMaxId = rightMax[i + k],
				currSum = (preSum[leftMaxId + k] - preSum[leftMaxId]) +			// left
							(preSum[i + k] - preSum[i]) +						// middle
							(preSum[rightMaxId + k] - preSum[rightMaxId]);		// right
			if (currSum > maxSum) {
				maxSum = currSum;
				ans = { leftMaxId, i, rightMaxId };
			}
		}

		return ans;
	}
};
// @lc code=end
