/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 */

// @lc code=start
class Solution {
public:
	long long maxKelements(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());

		long long score = 0;
		while (k--) {
			int n = pq.top(); pq.pop();
			score += n;
			pq.push(ceil(n / 3.0));
		}
		return score;
	}
};
// @lc code=end
