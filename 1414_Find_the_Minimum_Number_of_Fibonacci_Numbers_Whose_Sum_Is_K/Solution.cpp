#include <Solution.h>

int Solution::findMinFibonacciNumbers(int k) {

	vector<int> fab(2, 1);
	unordered_set<int> us;
	us.emplace(1);
	while (fab.back() < k) {
		int size = fab.size();
		fab.emplace_back(fab[size - 1] + fab[size - 2]);
	}

	int result = 0;
	int idx = fab.size() - 1;
	for (int i = fab.size() - 1 ; i >= 0 && k > 0 ; --i) {
		if (fab[i] > k) continue;
		k -= fab[i];
		++result;
	}
	return result;
}
