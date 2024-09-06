/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
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
	ListNode* modifiedList(vector<int>& nums, ListNode* head) {
		unordered_set<int> s(nums.begin(), nums.end());

		ListNode root(-1, head), *prev = &root, *curr = prev->next;
		while (curr) {
			if (s.count(curr->val)) {
				prev->next = curr->next;
				curr = curr->next;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
		return root.next;
	}
};
// @lc code=end
