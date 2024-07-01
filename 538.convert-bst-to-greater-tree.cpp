/*
 * @lc app=leetcode id=538 lang=cpp
 * @lcpr version=30204
 *
 * [538] Convert BST to Greater Tree
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
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return root;
		convertBST(root->right);
		accum += root->val;
		root->val = accum;
		convertBST(root->left);
		return root;
	}
};
// @lc code=end
