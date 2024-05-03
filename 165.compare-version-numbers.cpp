/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers 
 */

// @lc code=start
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int i1 = 0, i2 = 0, v1 = 0, v2 = 0;
		while (i1 < version1.length() || i2 < version2.length()) {
			while (i1 < version1.length() && version1[i1] != '.')
				v1 = v1 * 10 + (version1[i1++] - '0');

			while (i2 < version2.length() && version2[i2] != '.')
				v2 = v2 * 10 + (version2[i2++] - '0');

			if (v1 < v2) return -1;
			else if (v1 > v2) return 1;

			i1++; i2++;
			v1 = 0; v2 = 0;
		}
		return 0;
	}
};
// @lc code=end
