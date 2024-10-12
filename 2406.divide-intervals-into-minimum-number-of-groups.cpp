/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
class Solution {
public:
	int minGroups(vector<vector<int>>& intervals) {
		priority_queue<int, vector<int>, greater<int>> pq;
		sort(intervals.begin(), intervals.end());

		int groups = 0;
		for (const auto& i : intervals) {
			int start = i[0], end = i[1];

			if (!pq.empty() && pq.top() < start) {
				pq.pop();
				pq.push(end);
			} else {
				groups++;
				pq.push(end);
			}
		}
		return groups;
	}
};
// @lc code=end

