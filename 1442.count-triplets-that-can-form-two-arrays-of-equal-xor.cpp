/*
 * @lc app=leetcode id=1442 lang=cpp
 * @lcpr version=30202
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
class Solution {
public:
	int countTriplets(vector<int>& arr) {
		int ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			int curr = arr[i];
			for (int j = i + 1; j < arr.size(); j++) {
				curr ^= arr[j];
				if (curr == 0)
					ans += j - i;
			}
		}
		return ans;
	}
};
// @lc code=end
