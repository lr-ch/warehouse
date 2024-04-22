/*
 * @lc app=leetcode id=752 lang=cpp
 * @lcpr version=30122
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
	inline string roll_up(string& str, int digit) {
		string ret = str;
		if (ret[digit] == '9') ret[digit] = '0';
		else ret[digit]++;
		return ret;
	}

	inline string roll_down(string& str, int digit) {
		string ret = str;
		if (ret[digit] == '0') ret[digit] = '9';
		else ret[digit]--;
		return ret;
	}

public:
	int openLock(vector<string>& deadends, string target) {
		int steps = 0;
		unordered_set<string> visited, de(deadends.begin(), deadends.end());
		queue<string> q;
		q.push("0000");
		visited.insert("0000");

		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				auto curr = q.front(); q.pop();
				if (curr == target) return steps;

				for (int i = 0; i < curr.length(); i++) {
					auto next = roll_up(curr, i);
					if (!de.contains(curr) && !de.contains(next) && !visited.contains(next)) {
						visited.insert(next);
						q.push(next);
					}

					auto prev = roll_down(curr, i);
					if (!de.contains(curr) && !de.contains(prev) && !visited.contains(prev)) {
						visited.insert(prev);
						q.push(prev);
					}
				}
			}
			steps++;
		}
		return -1;
	}
};
// @lc code=end
