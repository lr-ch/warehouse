/*
 * @lc app=leetcode id=992 lang=cpp
 * @lcpr version=30121
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
	/*
	 * Ref. [2958] Length of Longest Subarray With at Most K Frequency
	 *
	 * Note. Here we need the count of subarrays at most K frequency
	 */
	int subarraysWithMostKDistinct(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		int left = -1, ans = 0;
		for (int right = 0; right < nums.size(); right++) {
			freq[nums[right]]++;

			// freq.size() is the count of distinct numbers in subarrays
			while (freq.size() > k) {
				left++;
				freq[nums[left]]--;
				if (freq[nums[left]] == 0)
					freq.erase(nums[left]);
			}
			ans += right - left;
		}
		return ans;
	}

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithMostKDistinct(nums, k)
                - subarraysWithMostKDistinct(nums, k - 1);
    }
};
// @lc code=end
