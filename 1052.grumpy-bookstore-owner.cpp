/*
 * @lc app=leetcode id=1052 lang=cpp
 * @lcpr version=30204
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  - 73/78 cases passed (N/A)
 */
class SolutionTLE {
	bool IsAvailable(vector<int>& customers, vector<int>& grumpy, int minutes, int visitors) {
		for (int calm = 0; calm < grumpy.size(); calm++) {
			int count = 0;
			for (int i = 0; i < customers.size(); i++)
				if (grumpy[i] == 0 || (i >= calm && i < calm + minutes))
					count += customers[i];
			if (count >= visitors) return true;
		}
		return false;
	}

public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int left = 0, right = accumulate(customers.begin(), customers.end(), 0);

		while (left < right) {
			int mid = right - (right - left) / 2;
			if (IsAvailable(customers, grumpy, minutes, mid))
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};

class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int initialCustomers = 0;
		int calmComeCustomers = 0;
		for (int i = 0; i < customers.size(); i++) {
			if (!grumpy[i])
				initialCustomers += customers[i];
			else if (i < minutes)
				calmComeCustomers += customers[i];
		}

		int maxCalmComeCustomers = calmComeCustomers;
		for (int i = minutes; i < grumpy.size(); i++) {
			calmComeCustomers += customers[i] * grumpy[i];		// even grumpy customers come
			calmComeCustomers -= customers[i - minutes] * grumpy[i - minutes];
			maxCalmComeCustomers = max(maxCalmComeCustomers, calmComeCustomers);
		}

		return initialCustomers + maxCalmComeCustomers;
	}
};
// @lc code=end
