/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
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
	long long kthLargestLevelSum(TreeNode* root, int k) {
		vector<long long> sums;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			long long sum = 0;
			for (int i = 0; i < size; ++i) {
				TreeNode* node = q.front(); q.pop();
				sum += node->val;
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			sums.push_back(sum);
		}
		sort(sums.begin(), sums.end(), greater<>());
		return k <= sums.size() ? sums[k - 1] : -1;
	}
};
// @lc code=end
