/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
class Solution {
public:
	long long dividePlayers(vector<int>& skill) {
		long long total = accumulate(skill.begin(), skill.end(), 0LL);
		if (total % (skill.size() / 2)) return -1;

		long long avg = total / (skill.size() / 2), chem = 0;

		unordered_map<int, int> table;
		for (const auto& s : skill) table[s]++;

		for (const auto& n : skill) {
			long long diff = avg- n;
			if (!table.contains(diff) || table[diff] == 0) return -1;
			table[diff]--;
			chem += (diff * n);
		}
		return chem / 2;    // added twice in the loop
	}
};
// @lc code=end
