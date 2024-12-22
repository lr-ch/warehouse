/*
 * @lc app=leetcode id=2940 lang=cpp
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */

// @lc code=start
class SolutionTLE {
	int find_building(vector<int>& heights, int f, int h) {
		for (int i = f; i < heights.size(); i++)
			if (heights[i] > h) return i;
		return -1;
	}

public:
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
		vector<int> ans;
		for (const auto& q : queries) {
			// case1. at the same building at beginning
			if (q[0] == q[1]) {
				ans.push_back(q[0]);
				continue;
			}

			// case2. someone is at bigger index and higher building, then meet there
			if ((q[0] < q[1] && heights[q[0]] < heights[q[1]]) ||
				(q[0] > q[1] && heights[q[0]] > heights[q[1]])) {
				ans.push_back(max(q[1], q[0]));
				continue;
			}

			// case3. otherwise, search...
			int from = max(q[0], q[1]), h = max(heights[q[0]], heights[q[1]]);
			ans.push_back(find_building(heights, from, h));
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
		vector<int> ans(queries.size(), -1);
		vector<pair<int, int>> pendingQueries;
		for (int i = 0; i < queries.size(); i++) {
			int &alice = queries[i][0], &bob = queries[i][1];

			// case. 1
			if (alice == bob) {
				ans[i] = alice;
				continue;
			}

			// case. 2
			if (alice > bob) swap(alice, bob);		// always put bob after alice
			if (heights[alice] < heights[bob]) {
				ans[i] = bob;
				continue;
			}

			// case. 3
			pendingQueries.push_back({ max(alice, bob), i });
		}

		sort(pendingQueries.begin(), pendingQueries.end(), greater<>());
		vector<pair<int, int>> monoStack;
		int last = heights.size() - 1;
		for (const auto& [_, id] : pendingQueries) {
			int alice = queries[id][0], bob = queries[id][1];

			while (last > bob) {
				while (!monoStack.empty() && heights[monoStack.back().second] < heights[last])
					monoStack.pop_back();
				monoStack.push_back({ heights[last], last });
				last--;
			}

			// check if the result exceeds boundary
			auto it = upper_bound(monoStack.rbegin(), monoStack.rend(), make_pair(heights[alice], heights.size()));
			if (it == monoStack.rend())
				ans[id] = -1;
			else
				ans[id] = it->second;
		}
		return ans;
	}
};
// @lc code=end
