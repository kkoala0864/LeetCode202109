#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool isBalanced(int num) {
	vector<int> cnt(10, 0);
	while (num) {
		int mod = num % 10;
		++cnt[mod];
		num /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] && i != cnt[i])
			return false;
	}
	return true;
}

int Solution::nextBeautifulNumber(int n) {
	for (int i = n + 1; i < 1300000; ++i) {
		if (isBalanced(i))
			return i;
	}
	return -1;
}
