/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
class Solution {
	bool validate(int n, vector<int>& quantities, int mid) {
		int stores = 0;
		for (const auto& q : quantities)
			// total stores = sum of (every products quantity / mid) +
			// (1 additional store if products quantity cannot be totally divided by mid)
			stores += q / mid + (q % mid ? 1 : 0);
		return stores <= n;
	}
public:
	int minimizedMaximum(int n, vector<int>& quantities) {
		int left = 1, right = 1e5;

		while (left < right) {
			int mid = left + (right - left) / 2;
			if (validate(n, quantities, mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};
// @lc code=end
