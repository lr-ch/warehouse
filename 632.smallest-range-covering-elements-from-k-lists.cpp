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
		priority_queue<
			tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>> candidates;
		int value_to = INT_MIN;

		// for each group, insert the first element into candidate
		for (int i = 0; i < nums.size(); i++) {
			candidates.push({nums[i][0], i, 1});
			value_to = max(value_to, nums[i][0]);
		}

		vector<int> result = {0, INT_MAX};
		while (true) {
			auto [value_from, groupid, pointer] = candidates.top();
			candidates.pop();

			if (value_to - value_from < result[1] - result[0])
				result = {value_from, value_to};

			// update the smallest candidate to its group's next element
			if (pointer < nums[groupid].size()) {
				candidates.push({nums[groupid][pointer], groupid, pointer + 1});

				// update value_to if new candidate is larger
				value_to = max(value_to, nums[groupid][pointer]);
			} else
				// stop if no more smallest element can join candidates
				break;
		}

		return result;
	}
};
// @lc code=end
