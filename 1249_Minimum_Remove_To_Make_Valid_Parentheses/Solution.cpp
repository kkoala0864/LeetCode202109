#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

string Solution::minRemoveToMakeValid(string s) {
	vector<char> st;
	int cnt = 0;

	while (!s.empty()) {
		if (s.back() == '(') {
			if (cnt == 0) {
				s.pop_back();
				continue;
			} else
				--cnt;
		} else if (s.back() == ')') {
			++cnt;
		}
		st.emplace_back(s.back());
		s.pop_back();
	}

	string result;
	cnt = 0;
	while (!st.empty()) {
		if (st.back() == ')') {
			if (cnt == 0) {
				st.pop_back();
				continue;
			} else
				--cnt;
		} else if (st.back() == '(') {
			++cnt;
		}
		result.push_back(st.back());
		st.pop_back();
	}
	return result;
}
