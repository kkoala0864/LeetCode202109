#include <data_type.h>
#include <stack>
#include <vector>
#include <algorithm>

using std::min;
using std::pair;
using std::stack;
using std::vector;

class CustomStack {
public:
	CustomStack(int maxSize) {
		_ms = maxSize;
	}

	void push(int x) {
		if (st.size() == _ms)
			return;
		st.push(x);
	}

	int pop() {
		if (st.empty())
			return -1;
		int size = st.size();
		int ret = st.top();
		st.pop();
		for (auto &i : increList) {
			if (i.first >= size) {
				--i.first;
				ret += i.second;
			}
		}
		return ret;
	}

	void increment(int k, int val) {
		increList.emplace_back(pair<int, int>(min(k, (int)st.size()), val));
	}

private:
	int _ms;
	vector<pair<int, int>> increList;
	stack<int> st;
	virtual ~CustomStack() {
	}
	CustomStack &operator=(const CustomStack &source);
	CustomStack(const CustomStack &);
};
