/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			auto target = find(arr.begin(), arr.end(), *iter * 2);
			if (target != arr.end() && target != iter) return true;
		}
		return false;
	}
};
// @lc code=end
