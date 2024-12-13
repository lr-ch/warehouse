/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
	long long pickGifts(vector<int>& gifts, int k) {
		priority_queue<int> pq(gifts.begin(), gifts.end());

		while (k--) {
			int g = pq.top(); pq.pop();
			pq.push(sqrt(g));
		}

		long long ans = 0;
		while (!pq.empty()) {
			ans += pq.top(); pq.pop();
		}

		return ans;
	}
};
// @lc code=end
