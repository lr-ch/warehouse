/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> to_sort = arr;
		sort(to_sort.begin(), to_sort.end());

		unordered_map<int, int> to_order;
		int rank = 1;
		for (const auto& n : to_sort)
			if (!to_order.contains(n))
				to_order[n] = rank++;

		for (int i = 0; i < arr.size(); i++)
			to_sort[i] = to_order[arr[i]];

		return to_sort;
	}
};
// @lc code=end

