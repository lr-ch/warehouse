/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
class Solution {
public:
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		vector<pair<int, int>> order;

		for (int i = 0; i < arr.size(); i++)
			for (int j = i + 1; j < arr.size(); j++)
				order.push_back({ arr[i], arr[j] });

		sort(order.begin(), order.end(), [](const auto& a, const auto& b) {
			return a.first * b.second < b.first * a.second;
		});

		return { order[k - 1].first, order[k - 1].second };
	}
};
// @lc code=end
