#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
int getVal(string &s, int &idx) {
	string val("");
	while (idx < s.size() && (s[idx] == ' ' || (s[idx] <= '9' && s[idx] >= '0'))) {
		if (s[idx] == ' ') {
			++idx;
			continue;
		}
		val.push_back(s[idx]);
		++idx;
	}
	return stoi(val);
}

int Solution::calculate(string s) {
	int idx = 0;
	vector<int> que(1, getVal(s, idx));
	while (idx < s.size()) {
		char oper = s[idx];
		++idx;
		int tmpVal = getVal(s, idx);
		if (oper == '*') {
			int tmp = que.back() * tmpVal;
			que.pop_back();
			que.emplace_back(tmp);
		} else if (oper == '/') {
			int tmp = que.back() / tmpVal;
			que.pop_back();
			que.emplace_back(tmp);
		} else if (oper == '-') {
			que.emplace_back(-tmpVal);
		} else {
			que.emplace_back(tmpVal);
		}
	}
	int result = 0;
	for (const auto &iter : que)
		result += iter;
	return result;
}
