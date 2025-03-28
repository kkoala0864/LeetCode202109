#include <Solution.h>
#include <iostream>

string Solution::removeKdigits(string num, int k) {
	if (num.size() <= k)
		return "0";
	string st;
	for (const auto &iter : num) {
		while (k > 0 && !st.empty() && st.back() > iter) {
			--k;
			st.pop_back();
		}
		if (iter == '0' && st.empty())
			continue;
		st.push_back(iter);
	}
	while (!st.empty() && k > 0) {
		st.pop_back();
		--k;
	}
	return st.empty() ? "0" : st;
}
