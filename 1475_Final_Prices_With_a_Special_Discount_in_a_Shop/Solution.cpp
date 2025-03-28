#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

vector<int> Solution::finalPrices(vector<int> &prices) {
	vector<int> result(prices.size(), 0);
	stack<int> st;
	for (int i = prices.size() - 1; i >= 0; --i) {
		while (!st.empty() && st.top() > prices[i]) {
			st.pop();
		}
		if (st.empty()) {
			result[i] = prices[i];
		} else {
			result[i] = prices[i] - st.top();
		}
		st.emplace(prices[i]);
	}
	return result;
}
