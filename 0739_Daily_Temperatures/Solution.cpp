#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

vector<int> Solution::dailyTemperatures(vector<int>& temperatures) {
	stack<int> st;
	vector<int> result(temperatures.size(), 0);
	int i = 0;
	while (i < temperatures.size()) {
		while (!st.empty()) {
			if (temperatures[i] > temperatures[st.top()]) {
				result[st.top()] = i - st.top();
				st.pop();
			} else {
				break;
			}
		}
		st.emplace(i);
		++i;
	}
	return result;
}
