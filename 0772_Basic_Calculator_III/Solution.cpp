#include <Solution.h>
#include <iostream>
#include <stack>

int getV(int o1, int o2, char oper) {
	if (oper == '+') return o1 + o2;
	else if (oper == '-') return o1 - o2;
	else if (oper == '*') return o1 * o2;
	else return o1 / o2;
}

void popAndExecute(stack<int>& vs, stack<char>& os) {
	int o2 = vs.top();
	vs.pop();
	int o1 = vs.top();
	vs.pop();
	char oper = os.top();
	os.pop();
	vs.emplace(getV(o1, o2, oper));
}

int cal(const string& s, int& idx) {
	stack<char> os;
	stack<int> vs;
	bool neg = false;
	while (idx < s.size() && s[idx] != ')') {
		if (s[idx] == '+' || s[idx] == '-' || s[idx] == '*' || s[idx] == '/') {
			if (s[idx] == '-') {
				os.emplace('+');
				neg = true;
			} else os.emplace(s[idx]);
		} else {
			int val = 0;
			if (s[idx] == '(') {
				++idx;
				val = cal(s, idx);
				if (neg) {
					val *= -1;
					neg = false;
				}
				vs.emplace(val);
			} else {
				string vStr;
				while (idx < s.size() && isdigit(s[idx])) {
					vStr.push_back(s[idx++]);
				}
				val = stoi(vStr);
				if (neg) {
					val *= -1;
					neg = false;
				}
				--idx;
				vs.emplace(val);
			}
			while (!os.empty() && (os.top() == '*' || os.top() == '/')) {
				popAndExecute(vs, os);
			}
		}
		++idx;
	}
	while (!os.empty()) {
		popAndExecute(vs, os);
	}
	return vs.top();
}

int Solution::calculate(string s) {
	int idx = 0;
	return cal(s, idx);
}
