/*
 * @lc app=leetcode id=950 lang=cpp
 * @lcpr version=30121
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> ans(deck.size());
		queue<int> emu;
		for (int i = 0; i < deck.size(); i++) emu.push(i);

		sort(deck.begin(), deck.end());
		for (int i = 0; i < deck.size(); i++) {
			int x = emu.front(); emu.pop();

			ans[x] = deck[i];

			int next = emu.front(); emu.pop();
			emu.push(next);
		}
		return ans;
	}
};
// @lc code=end
