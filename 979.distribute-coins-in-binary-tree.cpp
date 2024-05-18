/*
 * @lc app=leetcode id=979 lang=cpp
 * @lcpr version=30202
 *
 * [979] Distribute Coins in Binary Tree
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
	int balance(TreeNode* root, int& ans) {
		if (!root) return 0;

		int left = balance(root->left, ans),
			right = balance(root->right, ans);
		ans += abs(left) + abs(right);

		return root->val - 1 + left + right;
	}

public:
	int distributeCoins(TreeNode* root) {
		int ans = 0;
		balance(root, ans);
		return ans;
	}
};
// @lc code=end
