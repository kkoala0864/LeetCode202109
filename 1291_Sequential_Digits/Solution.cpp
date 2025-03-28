#include <Solution.h>
#include <iostream>

vector<int> Solution::sequentialDigits(int low, int high) {
	int lowSize = 0;
	int tmp = low;
	while (tmp > 0) {
		tmp /= 10;
		++lowSize;
	}
	int highSize = 0;
	tmp = high;
	while (tmp > 0) {
		tmp /= 10;
		++highSize;
	}
	vector<int> result;
	for (int size = lowSize; size <= highSize; ++size) {
		for (int base = 1; (base + size - 1) < 10; ++base) {
			int incre = base;
			int tmp = 0;
			for (int i = 0; i < size; ++i) {
				tmp = tmp * 10 + incre++;
			}
			if (tmp >= low && tmp <= high)
				result.emplace_back(tmp);
		}
	}
	return result;
}
