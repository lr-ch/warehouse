/*
 * @lc app=leetcode id=205 lang=cpp
 * @lcpr version=30121
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
	array<char, 256> dict1, dict2;
public:
	bool isIsomorphic(string s, string t) {
		// initialize dict with invalid ascii character
		fill(dict1.begin(), dict1.end(), 0);
		fill(dict2.begin(), dict2.end(), 0);

		for (int i = 0; i < s.length(); i++) {
			if (dict1[s[i]] == 0 && dict2[t[i]] == 0) {
				// if dict mapping is not created before, create mappings
				// e.g. [egg, add]
				// 'e' => 'a', 'g' => 'd'
				// 'a' => 'e', 'd' => 'g'
				dict1[s[i]] = t[i];
				dict2[t[i]] = s[i];
			} else if (dict1[s[i]] != 0 && dict2[t[i]] != 0) {
				// if mapping is created, check the mapping to current char
				if (dict1[s[i]] != t[i] || dict2[t[i]] != s[i])
					return false;
			} else
				// otherwise false case
				return false;
		}
		return true;
	}
};
// @lc code=end
