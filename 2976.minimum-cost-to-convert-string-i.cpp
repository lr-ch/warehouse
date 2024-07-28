/*
 * @lc app=leetcode id=2976 lang=cpp
 * @lcpr version=30204
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
class Solution {
public:
	long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
		vector<vector<int>> distance(26, vector<int>(26, INT_MAX / 2));
		for (int i = 0; i < 26; i++)
			distance[i][i] = 0;

		for (int i = 0; i < cost.size(); i++) {
			int from = original[i] - 'a', to = changed[i] - 'a';
			distance[from][to] = min(distance[from][to], cost[i]);
		}

		// Floyd-Warshall's algorithm
		for (int k = 0; k < 26; k++)
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++)
					if (distance[k][j] != INT_MAX / 2)
						distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);

		long long ans = 0;
		for (int i = 0; i < source.length(); i++) {
			int from = source[i] - 'a', to = target[i] - 'a';
			if (from != to) {
				if (distance[from][to] == INT_MAX / 2)
					return -1;
				ans += distance[from][to];
			}
		}
		return ans;
	}
};
// @lc code=end
