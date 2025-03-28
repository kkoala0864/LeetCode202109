#include <Solution.h>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

int Solution::validSubarraySize(vector<int> &nums, int threshold) {
	stack<int> st;
	int result = 0;

	int size = nums.size();
	vector<int> preSmaller(size, -1);
	vector<int> postSmaller(size, size);

	for (int i = 0; i < nums.size(); ++i) {
		while (!st.empty() && nums[st.top()] > nums[i]) {
			postSmaller[st.top()] = i;
			st.pop();
		}
		if (!st.empty()) {
			preSmaller[i] = st.top();
		}
		st.emplace(i);
	}
	for (int i = 0; i < nums.size(); ++i) {
		int cnt = postSmaller[i] - preSmaller[i] - 1;
		if (nums[i] > (threshold / cnt))
			return cnt;
	}
	return -1;
}
