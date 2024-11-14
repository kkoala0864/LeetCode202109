#include <Solution.h>
#include <iostream>

int check(int n, const vector<int>& quan, int k) {
	int cnt = 0;
	for (const auto& v : quan) {
		if (cnt > n) return -1;
		cnt += (v / k);
		if (v % k != 0) ++cnt;
	}
	if (cnt == n) return 0;
	else if (cnt < n) return 1;
	else return -1;
}

int Solution::minimizedMaximum(int n, vector<int>& quantities) {
	int l = 1;
	int r = 100000;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		int result = check(n, quantities, mid);
		if (result < 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
