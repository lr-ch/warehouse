/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
	vector<int> nodesBetweenCriticalPoints(ListNode* head) {
		ListNode *curr = head, *next = curr->next;

		// we only record the minimun distance, because the maximun distance
		// must be the index of last ct point - first ct point
		int first_ct_point = -1, prev_ct_point = -1, min_distance = INT_MAX;
		int prevVal = (curr->val < next->val ? INT_MIN : INT_MAX), point = 0;
		while (next) {
			if (curr->val < next->val) {
				// go down?
				if (prevVal > curr->val) {
					if (-1 == first_ct_point)
						first_ct_point = point;
					else
						min_distance = min(min_distance, point - prev_ct_point);

					prev_ct_point = point;
				}
			} else if (curr->val > next->val) {
				// go up?
				if (prevVal < curr->val) {
					if (-1 == first_ct_point)
						first_ct_point = point;
					else
						min_distance = min(min_distance, point - prev_ct_point);

					prev_ct_point = point;
				}
			}
			prevVal = curr->val;

			curr = next;
			next = curr->next;
			point++;
		}

		if (min_distance == INT_MAX) return {-1, -1};

		return { min_distance, prev_ct_point - first_ct_point };
	}
};
// @lc code=end
