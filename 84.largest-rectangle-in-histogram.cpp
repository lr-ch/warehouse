/*
 * @lc app=leetcode id=84 lang=cpp
 * @lcpr version=30122
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		/*
		 * ple[i], nle[i] => previous, next less element's index at #i
		 * e.g.1 heights = [ 2, 1, 5, 6, 2, 3]
		 *       nle     = [ 1, 6, 4, 4, 6, 6]
		 *       ple     = [-1,-1, 1, 2, 1, 4]
		 *
		 * e.g.2 heights = [ 2, 4]
		 *       nle     = [ 2, 2]
		 *       ple     = [-1, 0]
		 *
		 * Histogram area for each i is (height x width),
		 *       heights[i] * (nle[i] - ple[i] - 1)
		 */
		vector<int> ple(n, -1), nle(n, n);
		stack<int> st;                      // indices

		// find NLE (Next Less Element) for each index #i
		for (int i = 0; i < n; i++) {
			while (!st.empty() && heights[st.top()] > heights[i]) {
				nle[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}

		while (!st.empty()) st.pop();

		// find PLE (Previous Less Element) for each index #i
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && heights[st.top()] > heights[i]) {
				ple[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}

		int area = 0;
		for (int i = 0; i < n; i++)
			area = max(area, heights[i] * (nle[i] - ple[i] - 1));

		return area;
	}
};
// @lc code=end
