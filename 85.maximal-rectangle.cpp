/*
 * @lc app=leetcode id=85 lang=cpp
 * @lcpr version=30122
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
	/*
	 * ref. [84] Largest Rectangle in Histogram
	 */
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		vector<int> ple(n, -1), nle(n, n);
		stack<int> st;

		for (int i = 0; i < n; i++) {
			while (!st.empty() && heights[st.top()] > heights[i]) {
				nle[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}

		while (!st.empty()) st.pop();

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

public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int r = matrix.size(), c = matrix[0].size();
		vector<int> areas(c);
		int max_area = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				areas[j] = (matrix[i][j] == '0' ? 0 : areas[j] + 1);
			max_area = max(max_area, largestRectangleArea(areas));
		}

		return max_area;
	}
};
// @lc code=end
