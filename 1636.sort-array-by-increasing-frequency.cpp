/*
 * @lc app=leetcode id=1636 lang=cpp
 * @lcpr version=30204
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> freq;
		for (auto& i : nums) freq[i]++;

		vector<pair<int, int>> for_sort;
		for (auto& [i, f] : freq)
			for_sort.push_back({ f, i });
		sort(for_sort.begin(), for_sort.end(), [](const auto& a, const auto& b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		});

		int pos = 0;
		for (auto& [f, i] : for_sort) {
			fill(nums.begin() + pos, nums.begin() + pos + f, i);
			pos += f;
		}

		return nums;
	}
};
// @lc code=end
