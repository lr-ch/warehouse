/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
class Solution {
	// count how many numbers exist between prefix1 and prefix2
	inline int counter(long n, long prefix1, long prefix2) {
		int steps = 0;
		while (prefix1 <= n) {
			steps += min(n + 1, prefix2) - prefix1;
			prefix1 *= 10;
			prefix2 *= 10;
		}
		return steps;
	}

public:
	int findKthNumber(int n, int k) {
		int curr = 1;
		k--;

		while (k > 0) {
			int steps = counter(n, curr, curr + 1);
			if (steps > k) {
				curr *= 10;
				k--;
			} else {
				curr++;
				k -= steps;
			}
		}
		return curr;
	}
};
// @lc code=end
