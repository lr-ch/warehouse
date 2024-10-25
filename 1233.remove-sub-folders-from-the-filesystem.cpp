/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end());
		vector<string> res;

		for (const auto& f : folder)
			if (res.empty() || !f.starts_with(res.back()))
				res.push_back(f + '/');		// add trailing slash to prevent string overlapping

		for (auto& r : res)
			r.pop_back();					// remove trailing slash before return

		return res;
	}
};
// @lc code=end
