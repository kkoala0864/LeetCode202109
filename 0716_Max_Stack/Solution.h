#include <queue>
#include <stack>
#include <unordered_set>

using std::pair;
using std::priority_queue;
using std::stack;
using std::unordered_set;

class MaxStack {
public:
	MaxStack() {
		cnt = 0;
	}

	void push(int x) {
		++cnt;
		st.push({x, cnt});
		pq.push({x, cnt});
	}

	int pop() {
		while (!st.empty() && deleted.count(st.top().second))
			st.pop();
		if (st.empty())
			return -1;
		int val = st.top().first;
		deleted.emplace(st.top().second);
		st.pop();
		return val;
	}

	int top() {
		while (!st.empty() && deleted.count(st.top().second))
			st.pop();
		if (st.empty())
			return -1;
		return st.top().first;
	}

	int peekMax() {
		while (!pq.empty() && deleted.count(pq.top().second))
			pq.pop();
		if (pq.empty())
			return -1;
		return pq.top().first;
	}

	int popMax() {
		while (!pq.empty() && deleted.count(pq.top().second))
			pq.pop();
		if (pq.empty())
			return -1;
		deleted.emplace(pq.top().second);
		int val = pq.top().first;
		pq.pop();
		return val;
	}

private:
	int cnt;
	priority_queue<pair<int, int>> pq;
	stack<pair<int, int>> st;
	unordered_set<int> deleted;
	virtual ~MaxStack() {
	}
	MaxStack &operator=(const MaxStack &source);
	MaxStack(const MaxStack &);
};
