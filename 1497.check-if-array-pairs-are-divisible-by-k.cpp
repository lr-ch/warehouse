/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		vector<int> r(k);

		// in case i is negative
		for (const auto& i : arr) r[(i % k + k) % k]++;

		if (r[0] % 2) return false;

		for (int i = 1, j = r.size() - 1; i <= j; i++, j--)
			if (r[i] != r[j]) return false;
		return true;
	}
};
// @lc code=end
