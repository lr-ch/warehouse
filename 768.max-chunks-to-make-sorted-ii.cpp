/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		stack<int> sorted;

		for (int i = 0; i < arr.size(); i++) {
			int curr = arr[i];
			while (!sorted.empty() && arr[i] < sorted.top()) {
				curr = max(curr, sorted.top());
				sorted.pop();
			}
			sorted.push(curr);
		}
		return sorted.size();
	}
};
// @lc code=end
