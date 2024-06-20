/*
 * @lc app=leetcode id=1552 lang=cpp
 * @lcpr version=30204
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
	inline bool IsAvailable(vector<int>& position, int m, int distance) {
		// first position is put already, start from index#1
		int curr = position[0], count = 1;
		for (int i = 1; i < position.size(); i++)
			if (position[i] >= curr + distance) {
				curr = position[i];
				count++;
			}
		return count >= m;
	}

public:
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());
		int left = 1, right = position.back() - position.front();

		while (left < right) {
			int mid = right - (right - left) / 2;
			if (IsAvailable(position, m , mid))
				left = mid;				// increase distance
			else
				right = mid - 1;		// decrease distance
		}

		return left;
	}
};
// @lc code=end
