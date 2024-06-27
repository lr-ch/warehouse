/*
 * @lc app=leetcode id=1791 lang=cpp
 * @lcpr version=30204
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class SolutionCount {
public:
	int findCenter(vector<vector<int>>& edges) {
		unordered_map<int, int> count;
		for (const auto& e : edges) {
			count[e[0]]++;
			count[e[1]]++;
		}

		int maxi_n = 0, maxi_c = INT_MIN;
		for (const auto& [n, c] : count)
			if (c > maxi_c) {
				maxi_n = n;
				maxi_c = c;
			}
		return maxi_n;
	}
};

class SolutionTopology {
public:
	int findCenter(vector<vector<int>>& edges) {
		return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
					? edges[0][0] : edges[0][1];
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 60/60 cases passed (174 ms)
	 *  - Your runtime beats 26.7 % of cpp submissions
	 *  - Your memory usage beats 26.17 % of cpp submissions (85.5 MB)
	 */
	SolutionCount count;

	/*
	 * Accepted
	 *  - 60/60 cases passed (134 ms)
	 *  - Your runtime beats 67.07 % of cpp submissions
	 *  - Your memory usage beats 54.65 % of cpp submissions (70.8 MB)
	 */
	SolutionTopology topology;
public:
	int findCenter(vector<vector<int>>& edges) {
	//	return count.findCenter(edges);
		return topology.findCenter(edges);
	}
};
// @lc code=end
