#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

int Solution::evalRPN(vector<string>& tokens) {
	stack<int> st;
	int first = 0;
	int second = 0;
	int result = 0;
	for (const auto& iter : tokens) {
		if (iter == "*" || iter == "-" || iter == "+" || iter == "/") {
			second = st.top();
			st.pop();
			first = st.top();
			st.pop();
			if (iter == "*") {
				result = first * second;
			} else if (iter == "+") {
				result = first + second;
			} else if (iter == "-") {
				result = first - second;
			} else if (iter == "/") {
				result = first / second;
			}
		} else {
			result = stoi(iter);
		}
		st.emplace(result);
	}
	return st.top();
}
