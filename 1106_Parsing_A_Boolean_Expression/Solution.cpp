#include <Solution.h>
#include <iostream>
#include <stack>

void exec(bool& init, bool& cur, bool& v, char oper) {
	if (oper == '|') {
		cur = !init ? v : cur || v;
		init = true;
	} else if (oper == '!') {
		cur = !v;
	} else if (oper == '&') {
		cur = !init ? v : cur && v;
		init = true;
	} else if (oper == ' ') {
		cur = v;
	}
}

bool dfs(string& expression, int& idx, char oper) {
	if (idx >= expression.size()) return true;

	bool cur = false;
	bool init = false;
	while (idx < expression.size()) {
		if (expression[idx] == '|' || expression[idx] == '&' || expression[idx] == '!') {
			char nOper = expression[idx];
			idx += 2;
			bool ret = dfs(expression, idx, nOper);
			exec(init, cur, ret, oper);
		} else if (expression[idx] == ')') {
			++idx;
			return cur;
		} else if (expression[idx] == ',') {
			++idx;
		} else {
			bool v = expression[idx] == 't' ? true : false;
			exec(init, cur, v, oper);
			++idx;
		}
	}
	return cur;
}

bool Solution::parseBoolExpr(string expression) {
	int idx = 0;
	return dfs(expression, idx, ' ');
}
