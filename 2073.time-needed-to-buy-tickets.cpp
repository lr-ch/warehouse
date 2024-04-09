/*
 * @lc app=leetcode id=2073 lang=cpp
 * @lcpr version=30121
 *
 * [2073] Time Needed to Buy Tickets
 */

// @lc code=start
class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		int time = 0;
		for (int i = 0; i < tickets.size(); i++) {
			if (i <= k) {
				// for those who stands before k, the most time needed to buy their tickets
				// is min(tickets[i], tickets[k])
				time += min(tickets[i], tickets[k]);
			} else {
				// for those who stands behind k, the most time needed to buy their tickets
				// is min(tickets[k] - 1, tickets[i])
				time += min(tickets[k] - 1, tickets[i]);
			}
		}
		return time;
	}
};
// @lc code=end
