#include <Solution.h>

// [1, 3, 2]
// [1, 3, 2]
int Solution::kEmptySlots(vector<int> &bulbs, int k) {
	int size = bulbs.size();
	vector<int> t(size, -1);
	for (int i = 0 ; i < size ; ++i) {
		t[bulbs[i]-1] = i;
	}

	vector<int> preSmaller(size, -1);
	vector<int> nextSmaller(size, -1);
	stack<int> st;
	for  (int i = 0 ; i < size ; ++i) {
		while (!st.empty() && t[st.top()] > t[i]) {
			nextSmaller[st.top()] = i;
			st.pop();
		}
		if (!st.empty()) {
			preSmaller[i] = st.top();
		}
		st.emplace(i);
	}
	int result = INT_MAX;
	for (int i = 0 ; i < size ; ++i) {
		if (preSmaller[i] != -1) {
			if (abs(i - preSmaller[i]) == (k+1)) {
				result = min(result, max(t[i], t[preSmaller[i]]));
			}
		}
		if (nextSmaller[i] != -1) {
			if (abs(i - nextSmaller[i]) == (k+1)) {
				result = min(result, max(t[i], t[nextSmaller[i]]));
			}
		}
	}
	return result == INT_MAX ? -1 : result + 1;
}
