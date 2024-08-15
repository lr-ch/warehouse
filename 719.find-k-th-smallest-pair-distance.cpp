/*
 * @lc app=leetcode id=719 lang=cpp
 * @lcpr version=30204
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
class SolutionBF {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		vector<int> freq(nums.back() + 1);
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				freq[nums[j] - nums[i]]++;

		int count = 0;
		for (int i = 0; i < freq.size(); i++) {
			count += freq[i];
			if (count >= k)
				return i;
		}
		return 0;
	}
};

class SolutionBinarySearchDP {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		// left = the minimun distance, right = the maximun distance
		int left = 0, right = nums.back() - nums.front();
		while (left < right) {
			int mid = left + (right - left) / 2, count = 0, curr = 0;

			// calculate how many distances are larger than mid
			for (int i = 0; i < nums.size(); ++i) {
				while (curr < nums.size() && nums[i] - nums[curr] > mid) curr++;
				count += i - curr;
			}

			if (count < k)
				left = mid + 1;		// increase the distance
			else
				right = mid;		// decrease the distance
		}
		return right;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 19/19 cases passed (575 ms)
	 *  - Your runtime beats 7.18 % of cpp submissions
	 *  - Your memory usage beats 5.07 % of cpp submissions (26.2 MB)
	 */
	SolutionBF bf;

	/*
	 * Accepted
	 *  - 19/19 cases passed (3 ms)
	 *  - Your runtime beats 98.94 % of cpp submissions
	 *  - Your memory usage beats 26.29 % of cpp submissions (13 MB)
	 */
	SolutionBinarySearchDP bsdp;
public:
	int smallestDistancePair(vector<int>& nums, int k) {
	//	return bf.smallestDistancePair(nums, k);
		return bsdp.smallestDistancePair(nums, k);
	}
};
// @lc code=end
