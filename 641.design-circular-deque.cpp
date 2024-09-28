/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
	struct Node {
		Node *next;
		Node *prev;
		int val;
		Node(int val = 0, Node *prev = nullptr, Node *next = nullptr)
			: val(val), prev(prev), next(next) {}
	};

	Node *head, *tail;
	int capacity, size;
public:
	MyCircularDeque(int k) {
		head = nullptr;
		tail = nullptr;
		capacity = k;
		size = 0;
	}

	bool insertFront(int value) {
		if (isFull()) return false;

		if (head == nullptr) {
			head = new Node(value);
			tail = head;
		} else {
			Node *node = new Node(value, nullptr, head);
			head->prev = node;
			head = node;
		}
		size++;
		return true;
	}

	bool insertLast(int value) {
		if (isFull()) return false;

		if (tail == nullptr) {
			tail = new Node(value);
			head = tail;
		} else {
			Node *node = new Node(value, tail);
			tail->next = node;
			tail = node;
		}
		size++;
		return true;
	}

	bool deleteFront() {
		if (isEmpty()) return false;

		if (size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
		} else {
			Node *node = head->next;
			delete head;
			head = node;
		}
		size--;
		return true;
	}

	bool deleteLast() {
		if (isEmpty()) return false;

		if (size == 1) {
			delete tail;
			head = nullptr;
			tail = nullptr;
		} else {
			Node *node = tail->prev;
			delete tail;
			tail = node;
		}
		size--;
		return true;
	}

	int getFront() {
		return isEmpty() ? -1 : head->val;
	}

	int getRear() {
		return isEmpty()? -1 : tail->val;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

