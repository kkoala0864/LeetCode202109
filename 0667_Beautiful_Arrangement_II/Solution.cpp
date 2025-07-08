#include <Solution.h>

// 1 2 3 4 5 6 7 8 9
// 1 9 2 8 3 7 4 6 5
//  8 7 6 5 4 3 2 1
// 1 2 3 4 9 5 8 6 7
// 1 1 1 5 4 3 2 1
vector<int> Solution::constructArray(int n, int k) {
	vector<int> list;
	for (int i = 1 ; i <= n ; ++i) {
		list.emplace_back(i);
	}
	if (k == 1) return list;
	vector<int> result;
	int tail = n;
	int start = n - k;
	for (int i = 1 ; i < start ; ++i) result.emplace_back(i);
	while (start <= tail) {
		result.emplace_back(start);
		if (start < tail) {
			result.emplace_back(tail);
		}
		++start;
		--tail;
	}
	return result;
}
