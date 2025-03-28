#include <map>
#include <stack>

using std::map;
using std::stack;

class MinStack {
public:
	MinStack() {
	}

	void push(int val) {
		++_map[val];
		_st.emplace(val);
	}

	void pop() {
		int val = _st.top();
		_st.pop();
		--_map[val];
		if (_map[val] == 0)
			_map.erase(val);
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _map.begin()->first;
	}

private:
	map<int, int> _map;
	stack<int> _st;
	virtual ~MinStack() {
	}
	MinStack &operator=(const MinStack &source);
	MinStack(const MinStack &);
};
