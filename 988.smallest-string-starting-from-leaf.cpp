/*
 * @lc app=leetcode id=988 lang=cpp
 * @lcpr version=30122
 *
 * [988] Smallest String Starting From Leaf
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
	void dfs(TreeNode* r, string str) {
		if (!r) return;
		if (!r->left && !r->right) {
			if (res == "" || res > (char)('a' + r->val) + str)
				res = (char)('a' + r->val) + str;
			return;
		}

		dfs(r->left, (char)('a' + r->val) + str);
		dfs(r->right, (char)('a' + r->val) + str);
	}

	string res;
public:
	string smallestFromLeaf(TreeNode* root) {
		dfs(root, "");
		return res;
	}
};
// @lc code=end
