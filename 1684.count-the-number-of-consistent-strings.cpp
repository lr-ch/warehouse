/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
	typedef bitset<26> CharMap;
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		auto getCharMap = [](const string& s) -> CharMap {
			CharMap res;
			for (auto& ch : s) res.set(ch - 'a');
			return res;
		};

		CharMap a = getCharMap(allowed);
		int count = 0;
		for (const auto& word : words) {
			CharMap w = getCharMap(word);
			if (CharMap(~a & w).count() == 0)
				count++;
		}
		return count;
	}
};
// @lc code=end
