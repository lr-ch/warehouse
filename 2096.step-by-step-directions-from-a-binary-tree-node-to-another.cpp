/*
 * @lc app=leetcode id=2096 lang=cpp
 * @lcpr version=30204
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
	/*
	 * ref. [236] Lowest Common Ancestor of a Binary Tree
	 */
	TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
		if (!root) return root;
		if (root->val == p || root->val == q) return root;

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		if (left == nullptr) return right;
		if (right == nullptr) return left;

		return root;
	}

	bool bt(TreeNode* root, int val, string& path) {
		if (!root) return root;
		if (root->val == val) return true;

		path.push_back('L');
		if (bt(root->left, val, path)) return true;
		path.pop_back();

		path.push_back('R');
		if (bt(root->right, val, path)) return true;
		path.pop_back();

		return false;
	}

public:
	string getDirections(TreeNode* root, int startValue, int destValue) {
		TreeNode *lca = lowestCommonAncestor(root, startValue, destValue);

		string toStart, toDest;
		bt(lca, startValue, toStart);
		bt(lca, destValue, toDest);

		string ans;
		ans = string(toStart.length(), 'U');	// always up to lca
		ans += toDest;							// append path to dest
		return ans;
	}
};
// @lc code=end
