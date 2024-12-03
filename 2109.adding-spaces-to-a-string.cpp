/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		string ns(s.length() + spaces.size(), ' ');
		int currIndex = 0, spaceIndex = 0;
		for (int i = 0; i < s.length(); i++) {
			if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
				ns[currIndex++] = ' ';
				spaceIndex++;
			}
			ns[currIndex++] = s[i];
		}
		return ns;
	}
};
// @lc code=end
