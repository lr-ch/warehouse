/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
		for (int i = 0; i < score.size(); i++)
			pq.push({ score[i], i });

		vector<string> ans(score.size());
		int medal = 1;
		while (!pq.empty()) {
			auto [_, i] = pq.top(); pq.pop();
			switch (medal) {
				case 1 :
					ans[i] = "Gold Medal";
					medal++;
					break;
				case 2 :
					ans[i] = "Silver Medal";
					medal++;
					break;
				case 3 :
					ans[i] = "Bronze Medal";
					medal++;
					break;
				default :
					ans[i] = to_string(medal++);
					break;
			}
		}
		return ans;
	}
};
// @lc code=end
