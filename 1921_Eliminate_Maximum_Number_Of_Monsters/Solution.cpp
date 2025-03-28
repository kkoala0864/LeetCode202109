#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

int Solution::eliminateMaximum(vector<int> &dist, vector<int> &speed) {
	int size = dist.size();
	vector<int> t;
	for (int i = 0; i < size; ++i) {
		int rest = dist[i] % speed[i] > 0 ? 1 : 0;
		t.emplace_back((dist[i] / speed[i]) + rest);
	}

	sort(t.begin(), t.end());

	int result = 0;
	int baseT = 0;

	for (int i = 0; i < size; ++i) {
		if (t[i] <= baseT) {
			return i;
		} else {
			++result;
		}
		++baseT;
	}
	return size;
}
