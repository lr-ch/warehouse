/*
 * @lc app=leetcode id=1110 lang=cpp
 * @lcpr version=30204
 *
 * [1110] Delete Nodes And Return Forest
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
	TreeNode *dfs(TreeNode* r, unordered_set<int>& toDel) {
		if (!r) return r;

		r->left = dfs(r->left, toDel);
		r->right = dfs(r->right, toDel);

		if (toDel.count(r->val)) {
			if (r->left) forest.push_back(r->left);
			if (r->right) forest.push_back(r->right);
			delete r;
			return nullptr;
		}

		return r;
	}

	vector<TreeNode *> forest;
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		if (!root) return {};
		unordered_set<int> toDel(to_delete.begin(), to_delete.end());

		TreeNode *r = dfs(root, toDel);
		if (r) forest.push_back(r);

		return forest;
	}
};
// @lc code=end
