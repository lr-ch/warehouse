/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
	vector<int> data;
	int size;
public:
	CustomStack(int maxSize) {
		data.resize(maxSize);
		size = 0;
	}

	void push(int x) {
		if (size < data.size()) data[size++] = x;
	}

	int pop() {
		if (!size) return -1;
		return data[--size];
	}

	void increment(int k, int val) {
		for (int i = 0; i < min(static_cast<size_t>(k), data.size()); i++)
			data[i] += val;
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
