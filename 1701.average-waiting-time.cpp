/*
 * @lc app=leetcode id=1701 lang=cpp
 * @lcpr version=30204
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		double curr_time = customers[0][0], total_wait_time = 0;	// initial

		for (const auto& time : customers) {
			// wait time = time of wait for service + time of cook
			if (curr_time > time[0])
				total_wait_time += curr_time - time[0];		// wait time
			total_wait_time += time[1];						// cook time

			// forward timestamp
			curr_time = max(curr_time + time[1], (double)time[0] + time[1]);
		}

		return total_wait_time / customers.size();
	}
};
// @lc code=end
