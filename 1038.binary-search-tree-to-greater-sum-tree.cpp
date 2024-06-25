/*
 * @lc app=leetcode id=1038 lang=cpp
 * @lcpr version=30204
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
	int accum = 0;
public:
	TreeNode* bstToGst(TreeNode* root) {
		if (!root) return root;

		bstToGst(root->right);
		root->val += accum;
		accum = root->val;
		bstToGst(root->left);

		return root;
	}
};
// @lc code=end
