#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::nonSpecialCount(int l, int r) {
	vector<int> pl;
	int i = 2;
	for (; i <= sqrt(l-1) ; ++i) {
		bool find = false;
		for (const auto& v : pl) {
			if (i % v == 0) {
				find = true;
				break;
			}
		}
		if (!find) pl.emplace_back(i);
	}
	int ls = pl.size();
	for (; i <= sqrt(r) ; ++i) {
		bool find = false;
		for (const auto& v : pl) {
			if (i % v == 0) {
				find = true;
				break;
			}
		}
		if (!find) pl.emplace_back(i);
	}
	int rs = pl.size();
	return (r - l + 1) - (rs - ls);
}
