#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::reorderedPowerOf2(int n) {
	vector<vector<int>> cnt(32, vector<int>(10, 0));

	int base = 1;
	for (int i = 0 ; i < 32 ; ++i) {
		int val = base << i;
		while (val > 0) {
			++cnt[i][val % 10];
			val /= 10;
		}
	}

	vector<int> target(10, 0);
	while (n > 0) {
		++target[n % 10];
		n /= 10;
	}

	for (int i = 0 ; i < 32 ; ++i) {
		int j = 0;
		for (; j < 10 ; ++j) {
			if (target[j] != cnt[i][j]) break;
		}
		if (j == 10) return true;
	}
	return false;
}
