/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
class Solution {
public:
	string repeatLimitedString(string& s, int repeatLimit) {
		vector<int> freq(26, 0);
		for_each(s.begin(), s.end(), [&freq](const char& c) {
			freq[c - 'a']++;
		});

		priority_queue<
			pair<char, int>,
			vector<pair<char, int>>,
			less<>> pq;

		for (int i = 0; i < freq.size(); i++)
			if (freq[i] != 0) pq.push({ i + 'a', freq[i] });

		string ans;
		while (!pq.empty()) {
			auto [ch, f] = pq.top(); pq.pop();

			if (f > repeatLimit) {
				ans += string(repeatLimit, ch);
				f -= repeatLimit;

				// to avoid use the same 'ch' in next round,
				// pick next 'ch' and append to ans in this round
				if (!pq.empty()) {
					auto [nextCh, nextF] = pq.top(); pq.pop();

					// only need 1 ch
					ans += nextCh;
					nextF--;

					// put it back
					if (nextF > 0) pq.push({ nextCh, nextF });

					// also put it back
					pq.push({ ch, f });
				}
			} else
				ans += string(f, ch);
		}
		return ans;
	}
};
// @lc code=end
