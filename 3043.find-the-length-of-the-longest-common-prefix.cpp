/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class Solution {
	/*
	 * ref. [208] Implement Trie (Prefix Tree)
	 */
	class Trie {
		struct TrieNode {
			array<TrieNode *, 10> next;

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

		void insert(int num) {
			TrieNode *tmp = root;
			for (const auto& ch : to_string(num)) {
				int i = ch - '0';
				if (!tmp->next[i])
					tmp->next[i] = new TrieNode;
				tmp = tmp->next[i];
			}
		}

		int search(int num) {
			TrieNode *tmp = root;
			int len = 0;
			for (const auto& ch : to_string(num)) {
				int i = ch  - '0';
				if (tmp->next[i]) {
					len++;
					tmp = tmp->next[i];
				} else
					break;
			}
			return len;
		}
	};

public:
	int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
		Trie trie;

		for (const auto& n : arr1) trie.insert(n);

		int ans = 0;
		for (const auto& n : arr2) ans = max(ans, trie.search(n));

		return ans;
	}
};
// @lc code=end
