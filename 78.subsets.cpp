/*
 * @lc app=leetcode id=78 lang=cpp
 * @lcpr version=30202
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
	void bt(vector<int>& n, int i, int s, vector<int>& tmp) {
		if (tmp.size() == i) {
			ans.push_back(tmp);
			return;
		}

		for (int j = s; j < n.size(); ++j) {
			tmp.push_back(n[j]);
			bt(n, i, j + 1, tmp);
			tmp.pop_back();
		}
	}

	vector<vector<int>> ans;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> tmp;
		for (int i = 0; i <= nums.size(); ++i)
			bt(nums, i, 0, tmp);
		return ans;
	}
};
// @lc code=end
