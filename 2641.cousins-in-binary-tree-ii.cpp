/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
	void dfs_levelSum(TreeNode* root, int level) {
		if (!root) return;

		if (level < levelSum.size())
			levelSum[level] += root->val;
		else
			levelSum.push_back(root->val);

		dfs_levelSum(root->left, level + 1);
		dfs_levelSum(root->right, level + 1);
	}

	void dfs_replaceValue(TreeNode* parent, int cousin, int level) {
		if (!parent) return;

		int leftChild = parent->left ? parent->left->val : 0;
		int rightChild = parent->right ? parent->right->val : 0;

		if (level <= 1)
			parent->val = 0;
		else
			parent->val = levelSum[level] - parent->val - cousin;

		dfs_replaceValue(parent->left, rightChild, level + 1);
		dfs_replaceValue(parent->right, leftChild, level + 1);
	}

	vector<int> levelSum;
public:
	TreeNode* replaceValueInTree(TreeNode* root) {
		dfs_levelSum(root, 0);
		dfs_replaceValue(root, 0, 0);
		return root;
	}
};
// @lc code=end
