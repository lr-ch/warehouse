/*
 * @lc app=leetcode id=2458 lang=cpp
 *
 * [2458] Height of Binary Tree After Subtree Removal Queries
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
	int calNodesDepths(TreeNode *r, int depth) {
		if (!r) return 0;
		int leftDepth = calNodesDepths(r->left, depth + 1),
			rightDepth = calNodesDepths(r->right, depth + 1),
			subDepth = max({ leftDepth, rightDepth, depth });

		// record this node's depth, and its subtree's depth
		lvls[depth].push_back({ subDepth, r->val });
		mappings[r->val] = depth;

		return subDepth;
	}

	unordered_map<int, vector<pair<int, int>>> lvls;	// (depth, (node's total depths, node value))
	unordered_map<int, int> mappings;					// (node value, node depth)
public:
	vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
		calNodesDepths(root, 0);

		// sort each layer, by their nodes' total depths
		for (auto& [_, subtreeDepth] : lvls)
			sort(subtreeDepth.begin(), subtreeDepth.end(), greater<>());

		vector<int> res;
		for (const auto& q : queries) {
			int layer = mappings[q];					// use depth layer as index

			if (lvls[layer].size() == 1) {				// if this layer has only one node,
				res.push_back(layer - 1);				// the remain depth will be the depth of the layer - 1
				continue;
			}

			if (lvls[layer][0].second == q)				// remove query node is the maximun depths of all nodes in this layer
				res.push_back(lvls[layer][1].first);	// the remain depth will be the node has second maximum depths
			else
				res.push_back(lvls[layer][0].first);	// ot the depth is still the node with maximum depths
		}
		return res;
	}
};
// @lc code=end
