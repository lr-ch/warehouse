/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
class Solution {
public:
	int findChampion(int n, vector<vector<int>>& edges) {
		vector<int> in(n, 0);
		for (const auto& e : edges) in[e[1]]++;

		int ans = n;
		for (int i = 0; i < in.size(); i++) {
			// if indegree == 0
			if (in[i] == 0) {
				// check whether this is the only indgree == 0
				if (ans == n) ans = i;
				else return -1;
			}
		}
		return ans;
	}
};
// @lc code=end
