/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
	struct Node {
		int count;
		unordered_set<string> keys;
	};

	void remove(list<Node>::iterator it, const string& key) {
		it->keys.erase(key);
		if (it->keys.empty()) nodes.erase(it);
	}

	list<Node> nodes;	// keep nodes in ascending order of count
	unordered_map<string, list<Node>::iterator> table;
public:
	AllOne() {
	}

	void inc(string key) {
		if (0 == table.count(key)) {
			// insert a new node to nodes, but check count first
			if (nodes.empty() || nodes.front().count != 1)
				nodes.push_front({1, {key}});
			else
				nodes.front().keys.insert(key);
			table[key] = nodes.begin();
			return;
		}

		// duplicated string, change count of the node
		auto it = table[key], next_ = next(it);
		if (next_ == nodes.end() || next_->count != it->count + 1)
			next_ = nodes.insert(next_, {it->count + 1, {}});
		next_->keys.insert(key);
		table[key] = next_;

		remove(it, key);	// remove the old node
	}

	void dec(string key) {
		if (0 == table.count(key)) return;

		auto it = table[key];
		if (it->count > 1) {
			auto prev_ = prev(it);
			if (it == nodes.begin() || prev_->count != it->count - 1)
				prev_ = nodes.insert(it, {it->count - 1, {}});
			prev_->keys.insert(key);
			table[key] = prev_;
		} else
			table.erase(key);

		remove(it, key);	// remove the old node
	}

	string getMaxKey() {
		return nodes.empty() ? "" : *nodes.rbegin()->keys.begin();
	}

	string getMinKey() {
		return nodes.empty() ? "" : *nodes.begin()->keys.begin();
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
