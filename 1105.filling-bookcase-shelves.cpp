/*
 * @lc app=leetcode id=1105 lang=cpp
 * @lcpr version=30204
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		// dp[i] -> the minimun height when i-th book being set
		vector<int> dp(books.size() + 1);
		for (int i = 1; i <= books.size(); i++) {
			// create a new level for this book
			int thick = books[i - 1][0], height = books[i - 1][1];
			dp[i] = dp[i - 1] + height;

			// fill books until shelfWidth reached
			int j = i - 2;
			while (j >= 0 && thick + books[j][0] <= shelfWidth) {
				thick += books[j][0];
				height = max(height, books[j][1]);

				// update memo
				dp[i] = min(dp[i], dp[j] + height);
				j--;
			}
		}
		return dp[books.size()];
	}
};
// @lc code=end
