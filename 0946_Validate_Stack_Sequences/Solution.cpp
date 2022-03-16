#include <Solution.h>
#include <iostream>

bool Solution::validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	vector<int> st;

	int uIdx = 0, pIdx = 0;
	while (uIdx < pushed.size()) {
		st.emplace_back(pushed[uIdx]);
		++uIdx;
		while (uIdx < pushed.size() && pIdx < popped.size() && pushed[uIdx] == popped[pIdx]) {
			++pIdx;
			++uIdx;
		}

		while (!st.empty() && pIdx < popped.size() && st.back() == popped[pIdx]) {
			st.pop_back();
			++pIdx;
		}
	}

	return st.empty();
}
