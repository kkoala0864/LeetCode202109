#include <Solution.h>

// {4, 3, 2, 5, 5}
// {5, 4, 3, 6, 5}
// {6, 5, 4, 6, 6}
// 7, 6, 5, 7, 6
// 8, 7, 6, 7, 7
// 8, 8, 7, 8, 8
// 9, 9, 8, 9, 8
// 9, 10, 9, 10, 9
// 10, 10, 10, 11, 10
// 11, 11, 11, 11, 11
// increasing n-1 element 1 = minus 1 element
int Solution::minMoves(vector<int>& nums) {
	int minValue = INT_MAX;
	for (const auto& v : nums) minValue = min(v, minValue);
	int diff = 0;
	for (const auto& v : nums) diff += (v - minValue);
	return diff;
}
