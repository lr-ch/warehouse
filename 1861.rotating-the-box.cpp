/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		int R = box.size(), C = box[0].size();
		vector<vector<char>> res(C, vector<char>(R));

		// rotate the box
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				res[c][r] = box[R - r - 1][c];

		// start falling
		R = res.size(), C = res[0].size();
		for (int c = 0; c < C; c++) {
			int currR= R - 1;					// current row for placing stone
			for (int r = R - 1; r >= 0; r--) {
				if (res[r][c] == '#') {
					res[r][c] = '.';			// erase this grid and
					res[currR--][c] = '#';		// place the stone to upper row
												// and update row# for placing stone
				} else if (res[r][c] =='*')
					currR = r - 1;				// update row# for placing stone
			}
		}

		return res;
	}
};
// @lc code=end
