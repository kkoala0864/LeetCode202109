#include <Solution.h>
#include <iostream>

int Solution::findSpecialInteger(vector<int> &arr) {
	int v = arr.size() / 4;
	for (int i = 0; i < (arr.size() - v); ++i) {
		if (arr[i] == arr[i + v])
			return arr[i];
	}
	return -1;
}
