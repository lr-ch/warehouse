/*
 * @lc app=leetcode id=1122 lang=cpp
 * @lcpr version=30203
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> freq;
		for (const auto& n : arr1) freq[n]++;

		vector<int> ans;
		// handle numbers in arr2
		for (const auto& n : arr2)
			while (freq.count(n) && freq[n]--)
				ans.push_back(n);

		// handle remain numbers
		for (const auto& [n, c] : freq)
			if (c > 0)
				ans.insert(ans.end(), c, n);

		return ans;
	}
};
// @lc code=end
