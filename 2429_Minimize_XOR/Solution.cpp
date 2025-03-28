#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::minimizeXor(int num1, int num2) {
	int set2 = 0;
	int set1 = 0;

	for (int i = 0; i < 32; ++i) {
		if ((num2 >> i) & 1)
			++set2;
		if ((num1 >> i) & 1)
			++set1;
	}

	int result = 0;
	for (int i = 31; i >= 0 && set2 > 0; --i) {
		if ((num1 & (1 << i))) {
			result = result | (1 << i);
			--set2;
		}
	}

	if (set2 > 0) {
		for (int i = 0; i < 32 && set2 > 0; ++i) {
			if ((num1 & (1 << i)))
				continue;
			result = result | (1 << i);
			--set2;
		}
	}
	return result;
}
