#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minMoves(vector<vector<int>>& rooks) {
	int n = rooks.size();
	vector<int> x, y;

	for (int i = 0 ; i < n ; ++i) {
		x.emplace_back(rooks[i][0]);
		y.emplace_back(rooks[i][1]);
	}

	int result = 0;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0 ; i < n ; ++i) {
		result += abs(i-x[i]);
		result += abs(i-y[i]);
	}
	return result;
}
