#include <Solution.h>
#include <iostream>

int getDLen(int v) {
	int len = 0;
	while (v) {
		++len;
		v /= 10;
	}
	return len;
}

vector<int> Solution::sequentialDigits2(int low, int high) {
	int ll = getDLen(low), hl = getDLen(high);

	vector<int> result;
	for (int i = ll ; i <= hl ; ++i) {
		int v = 0;
		int mask = 0;
		for (int j = 1 ; j <= i ; ++j) {
			v *= 10;
			v += j;
			mask *= 10;
			mask += 1;
		}
		if (v >= low && v <= high) {
			result.emplace_back(v);
		}
		if (v > high) return result;
		for (int j = 2 ; j <= (9 - i + 1) ; ++j) {
			v += mask;
			if (v >= low && v <= high) {
				result.emplace_back(v);
			}
		}
	}
	return result;
}
