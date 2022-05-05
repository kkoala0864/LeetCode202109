#include <queue>

using std::queue;

class MyStack {
    public :
	MyStack() {}

	void push(int x) {
		_que.emplace(x);
		_top = x;
	}

	int pop() {
		for (int i = 1 ; i < _que.size() ; ++i) {
			_que.emplace(_que.front());
			_top = _que.front();
			_que.pop();
		}
		int result = _que.front();
		_que.pop();
		return result;
	}

	int top() {
		return _que.empty() ? -1 : _top;
	}

	bool empty() {
		return _que.empty();
	}
    private :
	queue<int> _que;
	int _top;
        virtual ~MyStack() {}
        MyStack& operator=(const MyStack& source);
        MyStack(const MyStack&);
};

