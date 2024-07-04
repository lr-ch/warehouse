/*
 * @lc app=leetcode id=2181 lang=cpp
 * @lcpr version=30204
 *
 * [2181] Merge Nodes in Between Zeros
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
class Solution {
public:
	ListNode* mergeNodes(ListNode* head) {
		ListNode *curr = head, *next = curr->next;
		while (next && next->next) {
			while (next->val != 0) {
				curr->val += next->val;
				next = next->next;
			}

			// now next->val == 0
			curr->next = next;

			// is this next the last 0?
			if (next->next == nullptr)
				curr->next = nullptr;

			curr = next;
			next = curr->next;
		}
		return head;
	}
};
// @lc code=end
