#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::max;
using std::stack;

int Solution::maxChunksToSortedStack(vector<int>& arr) {
	stack<int> st;
	st.emplace(arr[0]);
	int maxVal = 0;
	for (int i = 1 ; i < arr.size() ; ++i) {
		while (!st.empty() && arr[i] < st.top()) {
			maxVal = max(maxVal, st.top());
			st.pop();
		}
		st.push(max(maxVal, arr[i]));
	}
	return st.size();
}

int Solution::maxChunksToSorted(vector<int>& arr) {
	int i = 0;
	int maxVal = -1;
	int result = 0;
	while (i < arr.size()) {
		maxVal = max(maxVal, arr[i]);
		while (i <= maxVal) {
			maxVal = max(maxVal, arr[i++]);
		}
		++result;
	}
	return result;
}
