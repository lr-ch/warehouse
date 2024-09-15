/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution {
	array<int, 5> vowel = {{
						1, 2, 4, 8, 16		// a, e, i, o, u
					}};
public:
	int findTheLongestSubstring(string s) {
		int currMask = 0;
		unordered_map<int, int> m;			// (bitmask of vowels appeared, index)
		m[0] = -1;

		int ans = INT_MIN;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
				case 'a' :
					currMask ^= vowel[0];
					break;
				case 'e' :
					currMask ^= vowel[1];
					break;
				case 'i' :
					currMask ^= vowel[2];
					break;
				case 'o' :
					currMask ^= vowel[3];
					break;
				case 'u' :
					currMask ^= vowel[4];
					break;
				default :
					break;
			}

			if (!m.count(currMask)) m[currMask] = i;

			ans = max(ans, i - m[currMask]);
		}

		return ans;
	}
};
// @lc code=end
