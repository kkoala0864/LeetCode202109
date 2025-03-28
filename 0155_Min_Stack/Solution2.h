#include <stack>
#include <vector>
using std::stack;
using std::vector;

class MinStack {
public:
	MinStack() {
	}

	void push(int val) {
		int minVal = _st.empty() ? val : min(val, _st.top()[1]);
		_st.push({val, minVal});
	}

	void pop() {
		_st.pop();
	}

	int top() {
		return _st.top()[0];
	}

	int getMin() {
		return _st.top()[1];
	}

private:
	stack<vector<int>> _st;
	virtual ~MinStack() {
	}
	MinStack &operator=(const MinStack &source);
	MinStack(const MinStack &);
};
