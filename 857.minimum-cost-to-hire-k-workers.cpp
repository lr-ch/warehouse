/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		vector<pair<int, int>> workers;
		for (int i = 0; i < quality.size(); i++)
			workers.push_back({ quality[i], wage[i] });
		sort(workers.begin(), workers.end(), [](const auto& a, const auto& b) {
		//	return (double)a.second / a.first < (double)b.second / b.first;
			return a.second * b.first < b.second * a.first;
		});

		priority_queue<int> pq;
		int qualityTotal = 0;
		double ret = DBL_MAX;

		for (const auto& [q, w] : workers) {
			double unitWage = static_cast<double>(w) / q;
			qualityTotal += q;

			while (pq.size() > k - 1) {
				qualityTotal -= pq.top();
				pq.pop();
			}

			if (pq.size() == k - 1)
				ret = min(ret, unitWage * qualityTotal);

			pq.push(q);
		}

		return ret;
	}
};
// @lc code=end
