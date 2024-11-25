/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
	typedef vector<vector<int>> state;				// board state

	const vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	const state goal = { {1, 2, 3}, {4, 5, 0} };
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		set<state> visited;
		queue<pair<state, pair<int, int>>> q;		// (board state, position of 0)

		// find position of 0
		for (int r = 0; r < board.size(); r++)
			for (int c = 0; c < board[0].size(); c++)
				if (board[r][c] == 0) {
					q.push({ board, {r, c} });
					break;
				}

		// BFS
		int steps = 0;
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto [st, pos] = q.front(); q.pop();
				if (st == goal) return steps;
				visited.insert(st);
				for (const auto& [dr, dc] : dirs) {
					int nr = pos.first + dr, nc = pos.second + dc;
					if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size())
						continue;

					state next = st;
					// swap 0 from current to next position
					swap(next[pos.first][pos.second], next[nr][nc]);
					if (0 == visited.count(next)) q.push({ next, {nr, nc} });
				}
			}
			steps++;
		}

		return -1;
	}
};
// @lc code=end
