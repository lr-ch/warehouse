/*
 * @lc app=leetcode id=350 lang=cpp
 * @lcpr version=30204
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		vector<int> ans;
		for (int i = 0, j = 0; i < nums1.size(); i++)
			while (j < nums2.size()) {
				if (nums2[j] > nums1[i]) break;
				if (nums2[j] == nums1[i]) {
					ans.push_back(nums2[j]);
					j++;
					break;
				}
				if (nums2[j] < nums1[i])
					j++;
			}

		return ans;
	}
};
// @lc code=end
