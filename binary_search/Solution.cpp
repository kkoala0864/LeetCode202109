#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

// LeetCode #704
int Solution::general(vector<int> &list, int target) {
	int start = 0, end = list.size() - 1;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (list[mid] == target)
			return mid;
		if (list[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

// LeetCode #300
int Solution::findFirstBiggerThanMe(vector<int> &list, int target) {
	int start = 0, end = list.size() - 1;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (list[mid] == target)
			return mid;
		if (list[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

// LeetCode #153
int Solution::findMinimalValInRotatedArray(vector<int> &list) {
	int start = 0, end = list.size() - 1;
	int mid = 0;

	while (start < end) {
		mid = (end - start) / 2 + start;
		if (list[mid] > list[end])
			start = mid + 1;
		else
			end = mid;
	}
	return list[start];
}
