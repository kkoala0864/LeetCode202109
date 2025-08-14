#include <Solution.h>

bool check(vector<int>& order, int mid, long long k) {
	long long cnt = 0;
	long long accu = 0;
	long long size = order.size();
	for (long long i = 0; i < size; ++i) {
		if (order[i] > mid) {
			++accu;
		} else {
			cnt += (((1 + accu) * accu) / 2);
			accu = 0;
		}
	}
	if (accu > 0) cnt += (((1 + accu) * accu)/2);
	long long total = (1 + size) * size / 2;
	return (total - cnt) >= k;
}

int Solution::minTime(string s, vector<int>& order, int k) {
	int l = 0, r = s.size() - 1;
	int mid = 0;
	vector<int> rorder(s.size(), 0);
	for (int i = 0 ; i < s.size() ; ++i) {
		rorder[order[i]] = i;
	}

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (check(rorder, mid, k)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return check(rorder, l, k) ? l : -1;
}
