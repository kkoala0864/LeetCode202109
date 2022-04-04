#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

bool check(int num) {
	vector<int> cnt(10, 0);
	while (num) {
		++cnt[num % 10];
		num /= 10;
	}
	if (cnt[0] != 0) return false;
	for (int i = 1 ; i < cnt.size() ; ++i) {
		if (cnt[i] != 0 && cnt[i] != i) return false;
	}
	return true;
}

int Solution::nextBeautifulNumber2(int n) {
	for (int i = n + 1 ; i < 10000000; ++i) {
		if (check(i)) return i;
	}
	return 0;
}
