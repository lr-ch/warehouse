/*
 * @lc app=leetcode id=1915 lang=cpp
 * @lcpr version=30122
 *
 * [1915] Number of Wonderful Substrings
 */

// @lc code=start
class Solution {
public:
	long long wonderfulSubstrings(string word) {
		array<int, 1024> freq;	// letter in word = [a..j], 10 bits
		fill(freq.begin(), freq.end(), 0);
		freq[0] = 1;			// case of empty string

		long long ans = 0;
		int prefixMask = 0;
		for (const auto& ch : word) {
			prefixMask ^= (1 << ch - 'a');

			ans += freq[prefixMask];
			freq[prefixMask]++;

			for (char i = 0; i <= 'j' - 'a'; i++)
				ans += freq[prefixMask ^ (1 << i)];
		}

		return ans;
	}
};
// @lc code=end
