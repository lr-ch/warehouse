/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> xorSum(arr.size() + 1, 0);
		for (int i = 0; i < arr.size(); ++i)
			xorSum[i + 1] = xorSum[i] ^ arr[i];

		vector<int> ans;
		for (auto& q : queries) ans.push_back(xorSum[q[1] + 1] ^ xorSum[q[0]]);
		return ans;
	}
};
// @lc code=end

