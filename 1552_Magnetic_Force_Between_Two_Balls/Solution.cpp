#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

bool getResult(vector<int> &p, int m, int k) {
	int last = p[0];
	int cnt = 1;

	for (int i = 1; i < p.size() && cnt < m; ++i) {
		if (p[i] - last >= k) {
			++cnt;
			last = p[i];
		}
	}
	return cnt == m;
}

int Solution::maxDistance(vector<int> &position, int m) {
	sort(position.begin(), position.end());
	int diff = position.back() - position[0] + 1;

	int l = 1, r = diff, mid = 0;
	int result = 1;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (getResult(position, m, mid)) {
			result = mid;
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return result;
}
