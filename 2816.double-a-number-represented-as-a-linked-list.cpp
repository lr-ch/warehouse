/*
 * @lc app=leetcode id=2816 lang=cpp
 * @lcpr version=30201
 *
 * [2816] Double a Number Represented as a Linked List
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
	ListNode* reverse(ListNode* root) {
		ListNode* last = nullptr;
		while (root) {
			ListNode* tmp = root->next;
			root->next = last;
			last = root;
			root = tmp;
		}
		return last;
	}

public:
	ListNode* doubleIt(ListNode* head) {
		ListNode *reversed = reverse(head), *curr = reversed;

		int carry = 0;
		while (curr) {
			if (curr) {
				int doubled = curr->val * 2;
				curr->val = doubled % 10 + carry;
				carry = doubled / 10;
			}

			// handle the last bit node not enough
			if (!curr->next && carry) {
				curr->next = new ListNode(carry);
				break;
			}

			curr = curr->next;
		}

		return reverse(reversed);
	}
};
// @lc code=end
