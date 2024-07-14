/*
 * @lc app=leetcode id=726 lang=cpp
 * @lcpr version=30204
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
	map<string, int> dfs(const string& f, int& i) {
		map<string, int> count;
		while (i < f.length()) {
			switch (f[i]) {
				case '(' :
					{
						const auto& nb_count = dfs(f, ++i);
						int eleCount = elementCount(f, i);
						// add nb_count to current count
						for (const auto& [e, c] : nb_count)
							count[e] += c * eleCount;
						break;
					}
				case ')' :
					i++;
					return count;
				default :
					const string& element = elementName(f, i);
					count[element] += elementCount(f, i);
					break;
			}
		}
		return count;
	}

	string elementName(const string& f, int& i) {
		string element;
		// element is combination of alphabets
		// case 1. single upper case char
		// case 2. upper case char with lower case chars
		while (isalpha(f[i]) && (element.empty() || islower(f[i])))
			element += f[i++];
		return element;
	}

	int elementCount(const string& f, int& i) {
		string cnt;
		while (isdigit(f[i])) cnt += f[i++];
		return cnt.empty() ? 1 : atoi(cnt.c_str());
	}

public:
	string countOfAtoms(string formula) {
		string ans;
		int i = 0;
		auto res = dfs(formula, i);
		for (const auto& [e, c] : res) {
			ans += e;
			if (c > 1) ans += to_string(c);
		}
		return ans;
	}
};
// @lc code=end
