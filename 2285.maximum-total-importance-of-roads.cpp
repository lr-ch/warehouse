/*
 * @lc app=leetcode id=2285 lang=cpp
 * @lcpr version=30204
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution {
public:
	long long maximumImportance(int n, vector<vector<int>>& roads) {
		vector<long long> degree(n);

		for (const auto& r : roads) {
			degree[r[0]]++;
			degree[r[1]]++;
		}

		sort(degree.begin(), degree.end());

		long long ans = 0;
		for (int i = 0; i < degree.size(); i++)
			ans += (degree[i] * (i + 1));

		return ans;
	}
};
// @lc code=end
