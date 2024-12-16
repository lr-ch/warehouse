/*
 * @lc app=leetcode id=3264 lang=cpp
 *
 * [3264] Final Array State After K Multiplication Operations I
 */

// @lc code=start
class Solution {
public:
	vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
		priority_queue<
			pair<int, int>,
			vector<pair<int, int>>,
			greater<>> pq;
		for (int i = 0; i < nums.size(); i++) pq.push({ nums[i], i });

		while (k--) {
			auto [n, i] = pq.top(); pq.pop();
			pq.push({ n * multiplier, i});
		}

		while (!pq.empty()) {
			auto [n, i] = pq.top(); pq.pop();
			nums[i] = n;
		}

		return nums;
	}
};
// @lc code=end
