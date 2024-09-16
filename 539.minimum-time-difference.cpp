/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		bitset<24 * 60> timeSet;
		int first = INT_MAX, last = INT_MIN;
		for (auto& t : timePoints) {
			// HH * 60 + MM
			int tp = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));

			if (timeSet.test(tp)) return 0;
			timeSet.set(tp);

			first = min(first, tp);
			last = max(last, tp);
		}

		int ans = first + (1440 - last), pre = first;
		for (int curr = pre + 1; curr <= last; curr++)
			if (timeSet.test(curr)) {
				ans = min(ans, curr - pre);
				pre = curr;
			}

		return ans;
	}
};
// @lc code=end

