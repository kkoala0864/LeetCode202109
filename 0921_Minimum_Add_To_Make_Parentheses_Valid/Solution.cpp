#include <Solution.h>
#include <iostream>

int Solution::minAddToMakeValid(string s) {
	string st;
	int result = 0;
	for (const auto& c : s) {
		if (c == '(') st.push_back(c);
		else {
			if (st.empty()) {
				++result;
			} else {
				st.pop_back();
			}
		}
	}
	return result + st.size();
}
