/*
 * @lc app=leetcode id=1700 lang=cpp
 * @lcpr version=30121
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int circular = 0, square = 0;
		for (const auto& s : students) s ? square++ : circular++;

		for (const auto& s : sandwiches) {
			if (s == 0 && circular > 0) circular--;
			else if (s == 1 && square > 0) square--;
			else break;     // this sandwich will never be picked
		}

		return square + circular;
	}
};
// @lc code=end
