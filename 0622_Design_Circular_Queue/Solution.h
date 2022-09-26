#include <deque>

using std::deque;

class MyCircularQueue {
	public:
	MyCircularQueue(int k) {
		size = k;
	}

	bool enQueue(int value) {
		if (_cq.size() >= size) return false;
		_cq.emplace_back(value);
		return true;
	}

	bool deQueue() {
		if (_cq.empty()) return false;
		_cq.pop_front();
		return true;
	}

	int Front() {
		return _cq.empty() ? -1 : _cq.front();
	}

	int Rear() {
		return _cq.empty() ? -1 : _cq.back();
	}

	bool isEmpty() {
		return _cq.empty();
	}

	bool isFull() {
		return _cq.size() == size;
	}
	private:
	deque<int> _cq;
	int size;
};

