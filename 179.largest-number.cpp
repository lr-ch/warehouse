/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
			string sa = to_string(a), sb = to_string(b);
			return sa + sb > sb + sa;
		});

		string ans;
		bool allZero = true;
		for (auto& n : nums) {
			if (allZero && n != 0) allZero = false;
			ans += to_string(n);
		}
		return allZero ? "0" : ans;
	}
};
// @lc code=end
