#include <stack>
#include <climits>

using std::pair;
using std::stack;

class StockSpanner {
public:
	StockSpanner()
	    : idx(0) {
		st.emplace(pair<int, int>(INT_MAX, -1));
	}

	int next(int price) {
		while (st.top().first <= price) {
			st.pop();
		}
		int val = idx - st.top().second;
		st.emplace(pair<int, int>(price, idx));
		++idx;
		return val;
	}

private:
	stack<pair<int, int>> st;
	int idx;
	virtual ~StockSpanner() {
	}
	StockSpanner &operator=(const StockSpanner &source);
	StockSpanner(const StockSpanner &);
};
