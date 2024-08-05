/*
 * @lc app=leetcode id=2054 lang=cpp
 * @lcpr version=30204
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		priority_queue<pair<int, int>> pq;		// (value, start time)
		for (const auto& e : events) pq.push({ e[2], e[0] });

		// ascending sort by end time
		sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
			return a[1] < b[1];
		});

		int ans = INT_MIN;
		for (const auto& e : events) {
			int end = e[1], value = e[2];
			while (!pq.empty() && pq.top().second <= end)
				pq.pop();

			if (!pq.empty()) value += pq.top().first;
			ans = max(ans, value);
		}

		return ans;
	}
};
// @lc code=end
