/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
	bool evaluateTree(TreeNode* root) {
		if (!root) return false;		// should not happen
		if (!root->left && !root->right) return root->val ? true : false;

		switch (root->val) {
			case 2 :
				return evaluateTree(root->left) || evaluateTree(root->right);
			case 3 :
				return evaluateTree(root->left) && evaluateTree(root->right);
		}

		// should not come here
		return false;
	}
};
// @lc code=end
