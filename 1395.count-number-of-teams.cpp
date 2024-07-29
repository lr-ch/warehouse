/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution {
public:
	int numTeams(vector<int>& rating) {
		/*
		 * Fix middle man, the answer is sum of
		 *   leftSmaller * rightLarger + leftLarger * rightSmaller
		 */
		int ans = 0;
		for (int i = 1; i < rating.size() - 1; i++) {
			int leftSmaller = 0, leftLarger = 0, rightSmaller = 0, rightLarger = 0;
			for (int j = 0; j < i; j++) {
				if (rating[j] < rating[i]) leftSmaller++;
				if (rating[j] > rating[i]) leftLarger++;
			}

			for (int k = i + 1; k < rating.size(); k++) {
				if (rating[k] < rating[i]) rightSmaller++;
				if (rating[k] > rating[i]) rightLarger++;
			}

			ans += leftSmaller * rightLarger + leftLarger * rightSmaller;
		}

		return ans;
	}
};
// @lc code=end
