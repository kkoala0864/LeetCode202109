#include <stack>
#include <algorithm>
using std::min;
using std::pair;
using std::stack;

class MinStack {
public:
	MinStack() {
	}

	void push(int val) {
		int minVal = _st.empty() ? val : min(_st.top().second, val);
		_st.emplace(pair<int, int>(val, minVal));
	}

	void pop() {
		_st.pop();
	}

	int top() {
		return _st.top().first;
	}

	int getMin() {
		return _st.top().second;
	}

private:
	stack<pair<int, int>> _st;
	virtual ~MinStack() {
	}
	MinStack &operator=(const MinStack &source);
	MinStack(const MinStack &);
};
