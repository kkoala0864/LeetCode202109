#include <Solution.h>
#include <iostream>

int Solution::hIndex(vector<int> &citations) {
	int size = citations.size();

	for (int i = 0; i < size; ++i) {
		if (citations[i] >= (size - i))
			return size - i;
	}
	return 0;
}
