#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

int Solution::evalRPN2(vector<string>& tokens) {
	stack<int> st;
	int arg1 = 0, arg2 = 0, result = 0;
	for (int i = 0 ; i < tokens.size() ; ++i) {
		if (tokens[i].back() >= '0' && tokens[i].back() <= '9') {
			st.emplace(stoi(tokens[i]));
		} else {
			arg2 = st.top();
			st.pop();
			arg1 = st.top();
			st.pop();
			switch (tokens[i][0]) {
				case '+' :
					result = arg1 + arg2;
					break;
				case '-' :
					result = arg1 - arg2;
					break;
				case '*' :
					result = arg1 * arg2;
					break;
				case '/' :
					result = arg1 / arg2;
					break;
				default:
					break;
			}
			st.emplace(result);
		}
	}
	return st.top();
}
