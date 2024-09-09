/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	array<pair<int, int>, 4> dirs = {{
		{  0,  1 },
		{  1,  0 },
		{  0, -1 },
		{ -1,  0 }
	}};
public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
		vector<vector<int>> ans(m, vector<int>(n, -1));

		int row = 0, col = 0, dir = 0;
		while (head) {
			ans[row][col] = head->val;
			int nr = row + dirs[dir].first, nc = col + dirs[dir].second;

			if (nr < 0 || nr >= m || nc < 0 || nc >= n || ans[nr][nc] != -1)
				dir = (dir + 1) % dirs.size();
			row += dirs[dir].first;
			col += dirs[dir].second;
			head = head->next;
		}
		return ans;
	}
};
// @lc code=end

