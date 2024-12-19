/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		priority_queue<int> pq;
		int count = 0;
		for (int i = 0; i < arr.size(); i++) {
			pq.push(arr[i]);
			if (pq.top() == i) count++;
		}
		return count;
	}
};
// @lc code=end
