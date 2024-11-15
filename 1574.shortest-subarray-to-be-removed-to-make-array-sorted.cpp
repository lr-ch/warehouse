/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		/*
		 * a b c  |  d e f  |  g h i
		 * 0   left->   right->    n-1
		 *
		 * find two segments [0..left], [right..n-1] are ascending
		 */

		int n = arr.size();
		int right = n - 1;
		while (right > 0 && arr[right - 1] <= arr[right]) right--;
		if (right == 0) return 0;	// all ascending

		int res = right;			// remove arr[0..right-1]
		for (int left = 0; left < n; left++) {
			// if arr[left-1..left] is not ascending, then stop
			if (left > 0 && arr[left - 1] > arr[left]) break;

			// shift right if make [0..left], [right..n-1] are ascending
			while (right < n && arr[right] < arr[left]) right++;

			res = min(res, right - left - 1);
		}
		return res;
	}
};
// @lc code=end
