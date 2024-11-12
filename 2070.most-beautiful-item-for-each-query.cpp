/*
 * @lc app=leetcode id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */

// @lc code=start
class Solution {
public:
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		sort(items.begin(), items.end());

		/*
		 * make every price has the best beauties
		 * e.g. [[1,100],[2,10],[3,1]] -> [[1,100],[2,100],[3,100]]
		 */
		int current_best = INT_MIN;
		for_each(items.begin(), items.end(), [&current_best](auto &i) {
			current_best = max(current_best, i[1]);
			i[1] = current_best;
		});

		vector<int> res(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			// find the first item that price is larger than the query,
			// the real target is the previous one
			auto it = upper_bound(items.begin(), items.end(), queries[i],
						[](const auto& q, const auto& i) {
				if (i[0] > q) return true;
				return false;
			});

			if (it != items.begin())
				res[i] = (*prev(it))[1];
			else
				// find no prices can fit this large query
				res[i] = 0;
		}

		return res;
	}
};
// @lc code=end
