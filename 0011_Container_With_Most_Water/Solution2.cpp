#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maxArea2(vector<int> &height) {
	int result = 0;
	int left = 0, right = height.size() - 1;

	while (left < right) {
		int hg = min(height[left], height[right]);
		result = max((right - left) * hg, result);
		if (height[left] > height[right]) {
			--right;
		} else {
			++left;
		}
	}
	return result;
}
