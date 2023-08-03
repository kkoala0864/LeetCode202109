#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

vector<long long> Solution::minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
	vector<long long> dpr(regular.size() + 1, 0);
	vector<long long> dpe(regular.size() + 1, 0);
	vector<long long> result;

	dpe[0] = expressCost;

	long long lastMin = 0;
	for (int i = 1 ; i <= regular.size() ; ++i) {
		dpr[i] = lastMin + (long long)regular[i-1];
		dpe[i] = min(dpr[i-1] + (long long)expressCost + (long long)express[i-1], dpe[i-1] + (long long)express[i-1]);
		lastMin = min(dpr[i], dpe[i]);
		result.emplace_back(lastMin);
	}
	return result;

}
