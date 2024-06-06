/*
 * @lc app=leetcode id=846 lang=cpp
 * @lcpr version=30203
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		if (hand.size() % groupSize) return false;

		map<int, int> freq;
		for (const auto& h : hand) freq[h]++;

		while (!freq.empty()) {
			int group_start = freq.begin()->first;
			for (int i = 0; i < groupSize; i++) {
				if (!freq.count(group_start + i)) return false;

				freq[group_start + i]--;
				if (0 == freq[group_start + i]) freq.erase(group_start + i);
			}
		}
		return true;
	}
};
// @lc code=end
