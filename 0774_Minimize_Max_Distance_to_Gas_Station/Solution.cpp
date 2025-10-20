#include <Solution.h>
#include <cmath>

bool check(vector<int>& stations, int k, double v) {
	int cnt = 0;

	for (int i = 0 ; i < stations.size() - 1 ; ++i) {
		double cur = stations[i+1] - stations[i];
		double c = floor(cur / v);
		if ((v * c) == cur) --c;
		cnt += c;
	}
	return cnt <= k;
}

double Solution::minmaxGasDist(vector<int>& stations, int k) {
	double l = 0, r = 1e8;

	double mid = 0;

	while (l < r) {
		double n = (l + r) / 2;
		if (abs(n - mid) < 0.000001) {
			break;
		}
		mid = n;

		if (check(stations, k, mid)) {
			r = mid;
		} else {
			l = mid + 0.000001;
		}
	}
	return l;
}
