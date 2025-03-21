#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::stack;
using std::max;
using std::cout;
using std::endl;

int getMaxRectangle(const vector<int>& nums) {
	int n = nums.size();

	vector<int> preSmaller(n, -1);
	vector<int> nextSmaller(n, n);
	stack<int> st;
	for (int i = 0 ; i < n ; ++i) {
		while (!st.empty() && nums[st.top()] >= nums[i]) {
			nextSmaller[st.top()] = i;
			st.pop();
		}
		if (!st.empty()) {
			preSmaller[i] = st.top();
		}
		st.emplace(i);
	}
	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		result = max(result, (nextSmaller[i] - preSmaller[i] - 1) * nums[i]);
	}
	return result;
}

int Solution::maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<int> nums(n, 0);
	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (matrix[i][j] == '0') nums[j] = 0;
			else ++nums[j];
		}
		result = max(result, getMaxRectangle(nums));
	}
	return result;
}
