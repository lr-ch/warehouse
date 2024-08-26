/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
	void traverse(Node* root, vector<int>& v) {
		if (!root) return;

		for (const auto& n : root->children) traverse(n, v);
		v.push_back(root->val);
	}

public:
	vector<int> postorder(Node* root) {
		vector<int> v;
		traverse(root, v);
		return v;
	}
};
// @lc code=end

