/*
 * @lc app=leetcode id=2418 lang=cpp
 * @lcpr version=30204
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution {
public:
	vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		vector<pair<int, int>> people;
		for (int i = 0; i < names.size(); i++)
			people.push_back({ heights[i], i });
		sort(people.rbegin(), people.rend());

		vector<string> ans;
		for (const auto& [_, name] : people) ans.push_back(names[name]);
		return ans;
	}
};
// @lc code=end
