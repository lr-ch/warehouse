/*
 * @lc app=leetcode id=826 lang=cpp
 * @lcpr version=30203
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		vector<pair<int, int>> jobs;		// (difficulty, profit)
		for (int i = 0; i < difficulty.size(); i++)
			jobs.push_back({ difficulty[i], profit[i] });
		sort(jobs.begin(), jobs.end());
		sort(worker.begin(), worker.end());

		int ans = 0, maxi = 0, job = 0;
		for (const auto& ability : worker) {
			while (job < jobs.size() && jobs[job].first <= ability) {
				maxi = max(maxi, jobs[job].second);
				job++;
			}
			ans += maxi;
		}
		return ans;
	}
};
// @lc code=end
