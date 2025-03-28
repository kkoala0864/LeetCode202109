#include <Solution.h>
#include <iostream>

int Solution::calPoints(vector<string> &ops) {
	vector<int> st;
	int result = 0;
	for (const auto &op : ops) {
		if (op == "+") {
			int val = st.back();
			val += st[st.size() - 2];
			st.emplace_back(val);
			result += val;
		} else if (op == "D") {
			result += 2 * st.back();
			st.emplace_back(2 * st.back());
		} else if (op == "C") {
			result -= st.back();
			st.pop_back();
		} else {
			int val = stoi(op);
			result += val;
			st.emplace_back(val);
		}
	}
	return result;
}
