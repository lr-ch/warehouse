/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
class SolutionBS {
	bool isValidSF(vector<vector<int>>& g, int sf) {
		if (g[0][0] < sf || g[N - 1][N - 1] < sf) return false;

		queue<pair<int, int>> q;
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty()) {
			auto [r, c] = q.front(); q.pop();
			if (r == N - 1 && c == N - 1) return true;		// arrive destination

			for (auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc;

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || g[nr][nc] < sf)
					continue;

				q.push({ nr, nc });
				visited[nr][nc]= true;
			}
		}

		return false;
	}

	int N;
	const array<pair<int, int>, 4> dirs = {{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }};
public:
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		N = grid.size();
		queue<pair<int, int>> q;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (grid[r][c] == 1) {
					q.push({ r, c });
					grid[r][c] = 0;
				} else
					grid[r][c] = -1;

		// calculate safeness factor for each cell
		while (!q.empty()) {
			auto [r, c] = q.front(); q.pop();
			for (auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc, sf = grid[r][c];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || grid[nr][nc] != -1)
					continue;

				grid[nr][nc] = sf + 1;
				q.push({ nr, nc });
			}
		}

		// find out the maximun safeness factor
		int max_safe = 0;
		for_each(grid.begin(), grid.end(), [&](const auto& v) {
			max_safe = max(max_safe, *max_element(v.begin(), v.end()));
		});

		// search a path with valid SF between 0 ~ max_safe
		int left = 0, right = max_safe, res = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (isValidSF(grid, mid)) {
				res = mid;
				left = mid + 1;
			} else
				right = mid - 1;
		}

		return res;
	}
};

class SolutionGreedy {
	const array<pair<int, int>, 4> dirs = {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};
public:
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		int N = grid.size();
		queue<pair<int, int>> q;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (grid[r][c] == 1) {
					q.push({ r, c });
					grid[r][c] = 0;
				} else
					grid[r][c] = -1;

		// calculate safeness factor for each cell
		while (!q.empty()) {
			auto [r, c] = q.front(); q.pop();
			for (auto& [dr, dc] : dirs) {
				int nr = r + dr, nc = c + dc, sf = grid[r][c];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || grid[nr][nc] != -1)
					continue;

				grid[nr][nc] = sf + 1;
				q.push({ nr, nc });
			}
		}

		// always select maximun sf as next cell
		priority_queue<tuple<int, int, int>> pq;    // (sf, r, c)
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		pq.push({ grid[0][0], 0, 0 });
		visited[0][0] = true;

		while (!pq.empty()) {
			auto [sf, r, c] = pq.top(); pq.pop();

			if (r == N - 1 && c == N - 1) return sf;		// arrive destination

			for (auto& [dr, dc]: dirs) {
				int nr = r + dr, nc = c + dc;

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
					continue;
				pq.push({ min(sf, grid[nr][nc]), nr, nc });
				visited[nr][nc] = true;
			}
		}

		return 0;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 1036/1036 cases passed (466 ms)
	 *  - Your runtime beats 74.12 % of cpp submissions
	 *  - Your memory usage beats 65.81 % of cpp submissions (154.4 MB)
	 */
	SolutionBS bs;

	/*
	 * Accepted
	 *  - 1036/1036 cases passed (353 ms)
	 *  - Your runtime beats 91.69 % of cpp submissions
	 *  - Your memory usage beats 96.49 % of cpp submissions (117.6 MB)
	 */
	SolutionGreedy greedy;
public:
	int maximumSafenessFactor(vector<vector<int>>& grid) {
	//	return bs.maximumSafenessFactor(grid);
		return greedy.maximumSafenessFactor(grid);
	}
};
// @lc code=end
