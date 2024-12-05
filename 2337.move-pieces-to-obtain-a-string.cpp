/*
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
class Solution {
public:
	bool canChange(string_view start, string_view target) {
		int si = 0, ti = 0;
		while (si <= start.length() && ti <= target.length()) {
			// skip all '_'
			while (si < start.length() && start[si] == '_') si++;
			while (ti < target.length() && target[ti] == '_') ti++;

			// all 'R' and 'L' are found
			if (si == start.length() || ti == target.length())
				return si == target.length() && ti == target.length();

			// not match
			if (start[si] != target[ti]) return false;

			// check whether indices are overlapped
			if (start[si] == 'L' && si < ti) return false;
			if (start[si] == 'R' && si > ti) return false;

			si++;
			ti++;
		}

		// should not come here
		return false;
	}
};
// @lc code=end

