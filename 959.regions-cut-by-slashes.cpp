/*
 * @lc app=leetcode id=959 lang=cpp
 * @lcpr version=30204
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
class Solution {
	struct UnionSet {
		vector<int> boss;
		int groups;

		UnionSet(int n) : groups(n) {
			boss.resize(n);
			iota(boss.begin(), boss.end(), 0);
		}

		int find(int n) {
			while (boss[n] != n) {
				boss[n] = boss[boss[n]];
				n = boss[n];
			}
			return boss[n];
		}

		void unite(int x, int y) {
			int bossX = find(x);
			int bossY = find(y);
			if (bossX != bossY) {
				if (bossX < bossY)
					boss[bossY] = bossX;
				else
					boss[bossX] = bossY;
				groups--;
			}
		}
	};

public:
	/*
	 * a grid is splitted by imaginary lines into 4 pieces,
	 * yet the character is '/' or '\', the imaginary line becomes real
	 *
	 * case ' ' :
	 *  +---+
	 *  |\0/| area 0, 1, 2, 3 are connected,
	 *  |3X1| so merge (0, 1), (1, 2), (2, 3)
	 *  |/2\|
	 *  +---+
	 *
	 * case '\' :
	 *  +---+
	 *  |\0/| area (0, 1), (2, 3) are connected,
	 *  |3X1| so merge (0, 1), (2, 3)
	 *  |/2\|
	 *  +---+
	 *
	 * case '/' :
	 *  +---+
	 *  |\0/| area (0, 3), (1, 2) are connected,
	 *  |3X1| so merge (0, 3), (1, 2)
	 *  |/2\|
	 *  +---+
	 */
	int regionsBySlashes(vector<string>& grid) {
		int N = grid.size();
		UnionSet us(N * N * 4);					// each grid has 4 pieces

		// now traverse all the grids
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				int area_id = (r * N + c) * 4;	// each grid has 4 pieces
				switch (grid[r][c]) {
					case ' ' :
						us.unite(area_id + 0, area_id + 1);
						us.unite(area_id + 1, area_id + 2);
						us.unite(area_id + 2, area_id + 3);
						break;
					case '\\' :
						us.unite(area_id + 0, area_id + 1);
						us.unite(area_id + 2, area_id + 3);
						break;
					case '/' :
						us.unite(area_id + 0, area_id + 3);
						us.unite(area_id + 1, area_id + 2);
						break;
				}
				/*
				 * case merge to next column :
				 * +---+---+
				 * |\0/|\0/| merge area_id[1] to next column grid's area_id[3]
				 * |3X1|3X1|
				 * |/2\|/2\|
				 * +---+---+
				 */
				// merge to next column
				if (c < N - 1) us.unite(area_id + 1, area_id + 4 + 3);

				/*
				 * case merge to next row :
				 * +---+
				 * |\0/| merge area_id[2] to next row grid's area_id[0]
				 * |3X1|
				 * |/2\|
				 * +---+
				 * |\0/|
				 * |3X1|
				 * |/2\|
				 * +---+
				 */
				// merge to next row
				if (r < N - 1) us.unite(area_id + 2, area_id + 4 * N + 0);
			}
		}
		return us.groups;
	}
};
// @lc code=end
