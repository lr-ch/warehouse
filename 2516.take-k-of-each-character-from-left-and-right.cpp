/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
class Solution {
public:
	int takeCharacters(string s, int k) {
		vector<int> freq(3);
		for (const auto& ch : s) freq[ch - 'a']++;

		for (auto& f : freq) {
			if (f < k)
				return -1;	// not possible
			else
				f -= k;		// preserve k chars for condition,
							// the remain chars are the most chars we can take
		}

		// use sliding window to find the max number of chars we can take,
		// but do NOT exceeds freq[0..2]
		int left = 0, right = 0;
		while (right < s.length()) {
			freq[s[right] - 'a']--;

			// if any char is negative, we need to put it back
			// by move left pointer forward
			if (freq[0] < 0 || freq[1] < 0 || freq[2] < 0)
				freq[s[left++] - 'a']++;

			right++;
		}

		return s.length() - (right - left);
	}
};
// @lc code=end
