/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
class Solution {
public:
	int largestCombination(vector<int>& candidates) {
		vector<int> bitmap(24, 0);		// 0 ~ 24 bits
		for (const auto& c : candidates) {
			bitset<24> bits(c);			// 1 <= c <= 10^7
			for (int i = 0; i < 24; i++)
				if (bits.test(i)) bitmap[i]++;
		}
		return *max_element(bitmap.begin(), bitmap.end());
	}
};
// @lc code=end
