#include <Solution.h>
#include <iostream>

long long Solution::sumDigitDifferences(vector<int> &nums) {
	int size = 0;
	int v = nums[0];
	while (v) {
		++size;
		v /= 10;
	}
	vector<vector<long long>> digits(size, vector<long long>(10, 0));

	for (auto &v : nums) {
		for (int i = 0; i < size; ++i) {
			++digits[i][v % 10];
			v /= 10;
		}
	}
	long long result = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (digits[i][j] == 0)
				continue;
			for (int k = 0; k < j; ++k) {
				if (digits[i][k] == 0)
					continue;
				result += (digits[i][j] * digits[i][k]);
			}
		}
	}
	return result;
}
