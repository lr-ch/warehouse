/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */

// @lc code=start
class Solution {
public:
	int smallestChair(vector<vector<int>>& times, int targetFriend) {
		priority_queue<int, vector<int>, greater<int>> empty_chairs;
		vector<tuple<int, int, int>> friends(times.size());
		for (int i = 0; i < times.size(); ++i) {
			// {arrival, leave, index}
			friends[i] = make_tuple(times[i][0], times[i][1], i);
			empty_chairs.push(i);
		}
		sort(friends.begin(), friends.end());

		priority_queue<
			pair<int, int>,
			vector<pair<int, int>>,
			greater<pair<int, int>>> used_chairs;	// {leave time, chair no.}
		for (const auto& [arrival, leave, index] : friends) {
			// gather empty chairs before next friend's arrival
			while (!used_chairs.empty() && used_chairs.top().first <= arrival) {
				empty_chairs.push(used_chairs.top().second);
				used_chairs.pop();
			}

			// if the index is target, return the smallest unoccupied empty chair
			if (index == targetFriend) return empty_chairs.top();

			// else, use the smallest unoccupied chair to serve this friend
			used_chairs.push({leave, empty_chairs.top()});
			empty_chairs.pop();
		}

		// should not reach here
		return -1;
	}
};
// @lc code=end
