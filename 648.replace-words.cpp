/*
 * @lc app=leetcode id=648 lang=cpp
 * @lcpr version=30203
 *
 * [648] Replace Words
 */

// @lc code=start
class Solution {
	/*
	 * [208] Implement Trie (Prefix Tree)
	 */
	class Trie {
		struct TrieNode {
			array<TrieNode *, 26> next;
			bool terminated;

			TrieNode() {
				for (auto& it : next) it = nullptr;
				terminated = false;
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

		void insert(const string& word) {
			TrieNode *tmp = root;
			for (const auto& ch : word) {
				if (!tmp->next[ch - 'a'])
					tmp->next[ch - 'a'] = new TrieNode;
				tmp = tmp->next[ch - 'a'];
			}
			tmp->terminated = true;
		}

		string searchPrefix(const string& word) {
			string ans;
			TrieNode *tmp = root;
			for (const auto& ch : word) {
				if (!tmp->next[ch - 'a'])
					break;
				tmp = tmp->next[ch - 'a'];
				ans += ch;

				if (tmp->terminated) return ans;
			}
			return word;
		}
	};
public:
	string replaceWords(vector<string>& dictionary, string& sentence) {
		Trie dict;
		for (const auto& s : dictionary)
			dict.insert(s);

		string ans, tmp;
		istringstream is(sentence);
		while (is >> tmp)
			ans += (dict.searchPrefix(tmp) + " ");

		ans.pop_back();		// remove trailing space
		return ans;
	}
};
// @lc code=end
