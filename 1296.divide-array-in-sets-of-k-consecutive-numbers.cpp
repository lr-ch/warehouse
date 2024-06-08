/*
 * @lc app=leetcode id=1296 lang=cpp
 * @lcpr version=30203
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		if (nums.size() % k) return false;

		map<int, int> freq;
		for (const auto& n : nums) freq[n]++;

		while (!freq.empty()) {
			int start = freq.begin()->first;
			for (int i = 0; i < k; i++) {
				if (!freq.count(start + i)) return false;

				freq[start + i]--;
				if (freq[start + i] == 0) freq.erase(start + i);
			}
		}
		return true;
	}
};
// @lc code=end
