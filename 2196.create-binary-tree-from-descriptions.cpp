/*
 * @lc app=leetcode id=2196 lang=cpp
 * @lcpr version=30204
 *
 * [2196] Create Binary Tree From Descriptions
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
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		unordered_map<int, TreeNode *> tree;	// (value, root)
		unordered_set<int> children;
		for (const auto& d : descriptions) {
			if (!tree.count(d[0])) tree[d[0]] = { new TreeNode(d[0]) };
			if (!tree.count(d[1])) tree[d[1]] = { new TreeNode(d[1]) };
			children.insert(d[1]);

			// left child?
			if (d[2]) tree[d[0]]->left = tree[d[1]];
			else tree[d[0]]->right = tree[d[1]];
		}

		for (const auto& [v, n] : tree)
			if (children.count(v) == 0) return n;

		// should not come here
		return nullptr;
	}
};
// @lc code=end
