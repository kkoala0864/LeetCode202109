#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

long long Solution::putMarbles(vector<int>& weights, int k) {
	vector<long long> intervalSum(weights.size() - 1, 0);

	for (int i = 0 ; i < weights.size() - 1 ; ++i) {
		intervalSum[i] = weights[i] + weights[i+1];
	}

	sort(intervalSum.begin(), intervalSum.end());
	long long maxv = 0, minv = 0;
	for (int i = 0 ; i < (k-1) ; ++i) {
		maxv += intervalSum[intervalSum.size() - 1 - i];
		minv += intervalSum[i];
	}
	return maxv - minv;
}
