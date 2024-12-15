/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
class Solution {
	double passRatio(vector<vector<int>>& classes, int c, int inc) {
		return static_cast<double>(classes[c][0] + inc) / (classes[c][1] + inc);
	}

public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<pair<double, int>> pq;		// (gain, class#)

		for (int i = 0; i < classes.size(); i++)
			pq.push({ passRatio(classes, i, 1) - passRatio(classes, i, 0), i });

		while (extraStudents--) {
			auto [_, i] = pq.top(); pq.pop();
			classes[i][0]++;
			classes[i][1]++;
			pq.push({ passRatio(classes, i, 1) - passRatio(classes, i, 0), i });
		}

		double total = 0;
		for (int i = 0; i < classes.size(); i++)
			total += passRatio(classes, i, 0);

		return total / classes.size();
	}
};
// @lc code=end
