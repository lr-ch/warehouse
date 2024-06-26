/*
 * @lc app=leetcode id=1382 lang=cpp
 * @lcpr version=30204
 *
 * [1382] Balance a Binary Search Tree
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
	// inorder traversal, get sorted array
	void traverse(TreeNode* root) {
		if (!root) return;
		traverse(root->left);
		sorted.push_back(root->val);
		traverse(root->right);
	}

	// build BST by index of sorted array
	TreeNode* build(int left, int right) {
		if (left > right) return nullptr;

		int mid = right - (right - left) / 2;
		TreeNode *leftChild = build(left, mid - 1);
		TreeNode *rightChild = build(mid + 1, right);
		return new TreeNode(sorted[mid], leftChild, rightChild);
	}

	vector<int> sorted;
public:
	TreeNode* balanceBST(TreeNode* root) {
		traverse(root);
		return build(0, sorted.size() - 1);
	}
};
// @lc code=end
