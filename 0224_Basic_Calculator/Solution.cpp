#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

int getVal(const string& s, int& i) {
	int val = 0;
	while (i < s.size() && isdigit(s[i])) {
		val *= 10;
		val += (s[i] - '0');
		++i;
	}
	return val;
}

int doCal(const string& s, int& i) {
	int result = 0;
	while (i < s.size() && s[i] != ')') {
		if (isdigit(s[i])) {
			result += getVal(s, i);
		} else if (s[i] == '+') {
			++i;
			if (s[i] == '(') {
				++i;
				result += doCal(s, i);
			} else {
				result += getVal(s, i);
			}
		} else if (s[i] == '-') {
			++i;
			if (s[i] == '(') {
				++i;
				result -= doCal(s, i);
			} else {
				result += (-1 * getVal(s, i));
			}
		} else if (s[i] == '(') {
			++i;
			result += doCal(s, i);
		}
	}
	if (s[i] == ')') ++i;
	return result;
}

int Solution::calculate(string s) {
	int idx = 0;
	string trimSpace;
	for (const auto& c : s) if (c != ' ') trimSpace.push_back(c);
	return doCal(trimSpace, idx);
}
