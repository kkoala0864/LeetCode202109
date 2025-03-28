#include <data_type.h>
#include <iostream>

using std::cout;
using std::endl;

struct Node
{
	Node *next;
	Node *prev;
	int val;
	Node(int v) {
		val = v;
	}
	Node(int v, Node *n, Node *p) {
		val = v;
		next = n;
		prev = p;
	}
};

class MyCircularDeque {
public:
	MyCircularDeque(int k) {
		cap = k;
		cnt = 0;
		front = nullptr;
		tail = nullptr;
	}

	bool insertFront(int value) {
		if (cnt == cap)
			return false;
		if (!front) {
			Node *v = new Node(value, v, v);
			front = v;
			tail = v;
		} else {
			Node *v = new Node(value, front, tail);
			front->prev = v;
			tail->next = v;
			front = v;
		}
		++cnt;
		return true;
	}

	bool insertLast(int value) {
		if (cnt == cap)
			return false;
		if (!front) {
			Node *v = new Node(value, v, v);
			front = v;
			tail = v;
		} else {
			Node *v = new Node(value, front, tail);
			front->prev = v;
			tail->next = v;
			tail = v;
		}
		++cnt;
		return true;
	}

	bool deleteFront() {
		if (cnt == 0)
			return false;
		if (cnt == 1) {
			front = nullptr;
			tail = nullptr;
		} else {
			front->next->prev = tail;
			tail->next = front->next;
			front = front->next;
		}
		--cnt;
		return true;
	}

	bool deleteLast() {
		if (cnt == 0)
			return false;
		if (cnt == 1) {
			front = nullptr;
			tail = nullptr;
		} else {
			front->prev = tail->prev;
			tail->prev->next = front;
			tail = tail->prev;
		}
		--cnt;
		return true;
	}

	int getFront() {
		return front ? front->val : -1;
	}

	int getRear() {
		return tail ? tail->val : -1;
	}

	bool isEmpty() {
		return cnt == 0;
	}

	bool isFull() {
		return cnt == cap;
	}

private:
	Node *front;
	Node *tail;
	int cap;
	int cnt;
	virtual ~MyCircularDeque() {
	}
	MyCircularDeque &operator=(const MyCircularDeque &source);
	MyCircularDeque(const MyCircularDeque &);
};
