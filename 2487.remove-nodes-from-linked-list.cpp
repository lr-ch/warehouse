/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
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
	ListNode* reverse(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *last = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}

public:
	ListNode* removeNodes(ListNode* head) {
		ListNode* reversed = reverse(head), *root = reversed;
		while (root)
			if (root->next && root->next->val < root->val)
				root->next = root->next->next;
			else
				root = root->next;

		return reverse(reversed);
	}
};
// @lc code=end
