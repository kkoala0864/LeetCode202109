#include <Solution.h>

bool check(int v) {
	if (v == 0) return false;
	while (v > 0) {
		if ((v % 10) == 0) return false;
		v /= 10;
	}
	return true;
}

vector<int> Solution::getNoZeroIntegers(int n) {
	for (int i = 1 ; i <= (n / 2) ; ++i) {
		if (check(i) && check(n - i)) return vector<int>({i, n - i});
	}
	return vector<int>({-1, -1});
}
