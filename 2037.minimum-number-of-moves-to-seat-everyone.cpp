/*
 * @lc app=leetcode id=2037 lang=cpp
 * @lcpr version=30203
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());

		int ans = 0;
		for (int i = 0; i < seats.size(); i++)
			ans += abs(seats[i] - students[i]);
		return ans;
	}
};
// @lc code=end
