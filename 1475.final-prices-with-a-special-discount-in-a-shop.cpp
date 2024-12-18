/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		for (int i = 0; i < prices.size(); i++) {
			int j = i + 1;
			while (j < prices.size() && prices[j] > prices[i]) j++;

			if (j < prices.size()) prices[i] -= prices[j];
		}
		return prices;
	}
};
// @lc code=end
