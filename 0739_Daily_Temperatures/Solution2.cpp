#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

vector<int> Solution::dailyTemperatures2(vector<int> &temperatures) {
	stack<int> st;
	vector<int> result(temperatures.size(), 0);
	for (int i = 0; i < temperatures.size(); ++i) {
		while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
			result[st.top()] = i - st.top();
			st.pop();
		}
		st.emplace(i);
	}
	return result;
}
