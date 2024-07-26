/*
 * @lc app=leetcode id=1334 lang=cpp
 * @lcpr version=30204
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		// dist[i][j] -> distance between city#i and city#j
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
		// distance between city#i to city#i -> 0
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (const auto& e : edges) {
			int from = e[0], to = e[1], length = e[2];
			dist[from][to] = length;
			dist[to][from] = length;
		}

		// Floyd-Warshall's algorithm
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		int ans = 0, minimun = INT_MAX;
		for (int i = 0; i < n; i++) {
			int neighbors = 0;
			for (int j = 0; j < n; j++)
				if (dist[i][j] <= distanceThreshold)
					neighbors++;

			if (minimun >= neighbors) {
				minimun = neighbors;		// take least neighbors
				ans = i;					// take largest city#
			}
		}
		return ans;
	}
};
// @lc code=end
