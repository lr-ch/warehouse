/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
class Solution {
	/*
	 * ref. [208] Implement Trie (Prefix Tree)
	 */
	class Trie {
		struct TrieNode {
			array<TrieNode *, 26> next;
			int len = 0;

			TrieNode() {
				for (auto& it : next) it = nullptr;
			}
			~TrieNode() {
				for (auto& it : next) if (it) delete it;
			}
		};
		TrieNode *root;

	public:
		Trie() {
			root = new TrieNode;
		}

		void insert(const string& str) {
			TrieNode *tmp = root;
			for (const auto& ch : str) {
				int i = ch - 'a';
				if (!tmp->next[i])
					tmp->next[i] = new TrieNode;
				tmp->next[i]->len++;
				tmp = tmp->next[i];
			}
		}

		int score(const string& str) {
			TrieNode *tmp = root;
			int score = 0;
			for (const auto& ch : str) {
				int i = ch - 'a';
				score += tmp->next[i]->len;
				tmp = tmp->next[i];
			}
			return score;
		}
	};

public:
	vector<int> sumPrefixScores(vector<string>& words) {
		Trie trie;
		for (const auto& word : words) trie.insert(word);

		vector<int> res(words.size());
		for (int i = 0; i < words.size(); ++i)
			res[i] = trie.score(words[i]);
		return res;
	}
};
// @lc code=end
