#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::max;
using std::min;

int Solution::maxArea(vector<int> &height) {
	int left = 0;
	int right = height.size() - 1;

	int MaxSize = INT_MIN;

	while (left < right) {
		MaxSize = max(MaxSize, (right - left) * min(height[left], height[right]));

		if (height[left] > height[right]) {
			--right;
		} else {
			++left;
		}
	}
	return MaxSize;
}
