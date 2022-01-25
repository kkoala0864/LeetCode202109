#include <Solution.h>
#include <iostream>

bool Solution::validMountainArray(vector<int>& arr) {
	if (arr.size() < 3) return false;
	int i = 1;
	while (i < arr.size() && arr[i-1] < arr[i]) ++i;
	if (i == 1 || i == arr.size()) return false;
	while (i < arr.size() && arr[i-1] > arr[i]) ++i;
	return i == arr.size();
}
