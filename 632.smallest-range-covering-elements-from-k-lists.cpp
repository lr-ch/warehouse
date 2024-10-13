/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		// (value, group id, pointer to next)
		set<tuple<int, int, int>> candidates;

		// for each group, insert the first element into candidate
		for (int i = 0; i < nums.size(); i++)
			candidates.insert({nums[i][0], i, 1});

		vector<int> result = {0, INT_MAX};
		while (true) {
			auto [value_from, groupid_min, pointer_min] = *candidates.begin();
			auto [value_to, groupid_max, pointer_max] = *candidates.rbegin();

			if (value_to - value_from < result[1] - result[0]) {
				result[0] = value_from;
				result[1] = value_to;
			}

			// update the smallest candidate to its group's next element
			candidates.erase(candidates.begin());
			if (pointer_min < nums[groupid_min].size())
				candidates.insert({nums[groupid_min][pointer_min], groupid_min, pointer_min + 1});
			else
				// stop if no more smallest element can join candidates
				break;
		}

		return result;
	}
};
// @lc code=end
