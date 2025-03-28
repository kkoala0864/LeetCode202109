#include <Solution.h>
#include <iostream>

vector<int> Solution::grayCode2(int n) {
	vector<int> result;
	int size = 1 << n;
	for (int i = 0; i < size; ++i) {
		result.emplace_back(i ^ (i >> 1));
	}
	return result;
}
