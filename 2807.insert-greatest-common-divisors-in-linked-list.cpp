/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
		ListNode root(0, head), *curr = head, *next = curr->next;

		while (curr && next) {
			ListNode *node = new ListNode(gcd(curr->val, next->val), next);
			curr->next = node;
			curr = next;
			next = next->next;
		}
		return root.next;
	}
};
// @lc code=end
