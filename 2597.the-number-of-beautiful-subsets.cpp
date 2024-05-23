/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
class Solution {
	inline bool isBeautiful(vector<int>& v, int i) {
		if (find(v.begin(), v.end(), i + diff) != v.end()) return false;
		if (find(v.begin(), v.end(), i - diff) != v.end()) return false;
		return true;
	}

	void bt(vector<int>& n, int cap, int start, vector<int>& curr) {
		if (curr.size() == cap) {
			ans++;
			return;
		}

		for (int i = start; i < n.size(); i++) {
			if (!isBeautiful(curr, n[i]))
				continue;
			curr.push_back(n[i]);
			bt(n, cap, i + 1, curr);
			curr.pop_back();
		}
	}

	int diff, ans = 0;
public:
	int beautifulSubsets(vector<int>& nums, int k) {
		diff = k;
		vector<int> tmp;
		for (int i = 1; i <= nums.size(); i++)
			bt(nums, i, 0, tmp);
		return ans;
	}
};
// @lc code=end
