/*
 * @lc app=leetcode id=1482 lang=cpp
 * @lcpr version=30204
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
	inline bool IsAvailable(vector<int>& bloomDay, int m, int k, int d) {
		int adjs = 0, bouquets = 0;
		for (const auto& day : bloomDay) {
			if (day <= d) {
				adjs++;
				if (adjs == k) {
					bouquets++;
					adjs = 0;
				}
			} else
				adjs = 0;

			if (bouquets == m) return true;
		}
		return false;
	}

public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		// e.g. bloomDay = [1,10,3,10,2], m = 3, k = 2
		if (bloomDay.size() < (unsigned long)m * k) return -1;

		int left = 0, right = 0;	// the fastest/slowest bloom flowers
		for (const auto& d : bloomDay) {
			left = min(left, d);
			right = max(right, d);
		}

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (IsAvailable(bloomDay, m, k, mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};
// @lc code=end
