#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxArea3(vector<int> &height) {
	int result = 0;
	int start = 0, end = height.size() - 1;
	while (start < end) {
		result = max(result, (end - start) * min(height[start], height[end]));
		if (height[start] > height[end]) {
			--end;
		} else {
			++start;
		}
	}
	return result;
}
