/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
	vector<int> dfs(const string& str) {
		if (memo.count(str)) return memo[str];

		vector<int> res;

		for (int i = 0; i < str.length(); ++i) {
			char op = str[i];

			// split into left and right side based on the op
			if (op == '+' || op == '-' || op == '*') {
				auto left = dfs(str.substr(0, i));
				auto right = dfs(str.substr(i + 1));

				for (int j = 0; j < left.size(); ++j)
					for (int k = 0; k < right.size(); ++k) {
						if (op == '+') res.push_back(left[j] + right[k]);
						else if (op == '-') res.push_back(left[j] - right[k]);
						else if (op == '*') res.push_back(left[j] * right[k]);
					}
			}
		}

		// edge case, the final part which cannot be splited
		if (res.empty()) res.push_back(stoi(str));
		return memo[str] = res;
	}

	unordered_map<string, vector<int>> memo;
public:
	vector<int> diffWaysToCompute(string expression) {
		return dfs(expression);
	}
};
// @lc code=end
