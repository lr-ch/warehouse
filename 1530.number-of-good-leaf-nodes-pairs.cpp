/*
 * @lc app=leetcode id=1530 lang=cpp
 * @lcpr version=30204
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
	 * leavesDistanceCount(r)[d] : at node r, there are [d] leaves with distance d
	 *   e.g.    1        leavesDistanceCount(1) = [0, 2],
	 *          / \                   at node#1, there are 0 leaves at distance 0
	 *         2   3                             there are 2 leaves at distance 1
	 */
	vector<int> leavesDistanceCount(TreeNode* r, int d) {
		vector<int> result(d + 1);		// normalize return buffer

		if (!r) return result;

		// leaf
		if (!r->left && !r->right) {
			result[0] = 1;				// a leaf has distance 0 with itself only
			return result;
		}

		// not leaf
		auto left = leavesDistanceCount(r->left, d);
		auto right = leavesDistanceCount(r->right, d);
		for (int l = 0; l < left.size(); l++)
			for (int r = 0; r < right.size(); r++)
				if (l + r + 1 < d)
					count += (left[l] * right[r]);		// permutation rule

		for (int i = 0; i < d; i++)
			// the distance increase by 1 for adding this parent node
			result[i + 1] = left[i] + right[i];
		return result;
	}

	int count = 0;
public:
	int countPairs(TreeNode* root, int distance) {
		leavesDistanceCount(root, distance);
		return count;
	}
};
// @lc code=end
