/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
	bool dfs(ListNode* curr, TreeNode* node) {
		if (!curr) return true;		// compare complete
		if (!node) return false;	// nore more children to compare

		if (curr->val == node->val)
			return dfs(curr->next, node->left) || dfs(curr->next, node->right);
		return false;
	}

public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (!root) return false;
		return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
	}
};
// @lc code=end
