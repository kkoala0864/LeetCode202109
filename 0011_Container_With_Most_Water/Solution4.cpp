#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxArea4(vector<int>& height) {
	int start = 0, end = height.size()-1;
	int result = 0;
	while (start < end) {
		result = max(result, (end - start) * min(height[start], height[end]));
		if (height[start] < height[end]) ++start;
		else if (height[start] > height[end]) --end;
		else {
			++start;
			--end;
		}
	}
	return result;
}
