#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

double Solution::averageWaitingTime(vector<vector<int>>& customers) {
	double wait = 0;
	double end = 0;

	for (const auto& c : customers) {
		end = max((double)(end + c[1]), (double)(c[0] + c[1]));
		wait += (end - (double)c[0]);
	}
	return wait / (double)customers.size();
}
