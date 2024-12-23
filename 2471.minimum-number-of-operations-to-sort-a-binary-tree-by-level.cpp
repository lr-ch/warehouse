/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
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
	int sort_counter(vector<int>& v) {
		vector<int> s = v;      // to sort
		sort(s.begin(), s.end());

		unordered_map<int, int> pos;
		for (int i = 0; i < v.size(); i++) {
			pos[v[i]] = i;
		}

		int swaps = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != s[i]) {
				swaps++;
				int curPos = pos[s[i]];
				pos[v[i]] = curPos;
				swap(v[curPos], v[i]);
			}
		}
		return swaps;
	}

public:
	int minimumOperations(TreeNode* root) {
		queue<TreeNode *> q;
		q.push(root);
		int counter = 0;

		while (!q.empty()) {
			int qsize = q.size();
			vector<int> values(qsize);

			for (int i = 0; i < qsize; i++) {
				auto node = q.front(); q.pop();
				values[i] = node->val;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}

			counter += sort_counter(values);
		}
		return counter;
	}
};
// @lc code=end
