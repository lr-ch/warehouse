/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
	// the order matters!!
	array<pair<int, int>, 4> dirs = {{
									{ 0,  1},	// right
									{ 1,  0},	// down
									{ 0, -1},	// left
									{-1,  0}	// up
								}};
public:
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
		vector<vector<int>> res;
		res.push_back({rStart, cStart});

		int stride = 0, curr = 0, nextR = rStart, nextC = cStart;
		while (res.size() < rows * cols) {
			// only to right/left, the stride increases
			if (curr == 0 || curr == 2) stride++;
			for (int i = 0; i < stride; i++) {
				nextR += dirs[curr].first;
				nextC += dirs[curr].second;
				if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols)
					res.push_back({ nextR, nextC });
			}
			curr = (curr + 1) % 4;
		}
		return res;
	}
};
// @lc code=end
