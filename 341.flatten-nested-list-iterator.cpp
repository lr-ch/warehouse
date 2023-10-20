/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
	vector<NestedInteger>::iterator curr;
	stack<vector<NestedInteger>::iterator> begins, ends;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}

	int next() {
		int res = begins.top()->getInteger();
		begins.top()++;
		return res;
	}

	bool hasNext() {
		while (!begins.empty()) {
			if (begins.top() == ends.top()) {
				begins.pop();
				ends.pop();
			} else {
				curr = begins.top();
				if (curr->isInteger()) return true;

				begins.top()++;
				begins.push(curr->getList().begin());
				ends.push(curr->getList().end());
			}
		}
		return false;
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
