/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* reverseOddLevels(TreeNode* root) {
		if (!root) return root;

		queue<TreeNode *> q;
		q.push(root);
		int lvl = 0;
		while (!q.empty()) {
			int qsize = q.size();
			vector<TreeNode *> tmp;
			while (qsize--) {
				auto node = q.front(); q.pop();

				if (lvl % 2) tmp.push_back(node);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			if (lvl % 2) {
				for (int i = 0; i < (tmp.size() / 2); i++)
					swap(tmp[i]->val, tmp[tmp.size() - 1 - i]->val);
			}

			lvl++;
		}
		return root;
	}
};
// @lc code=end
