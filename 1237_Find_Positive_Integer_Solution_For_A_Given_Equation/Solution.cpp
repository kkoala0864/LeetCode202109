#include <Solution.h>
#include <iostream>

vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
	vector<vector<int>> result;

	for (int i = 1; i <= z; ++i) {
		int l = 1, r = 1000;
		int mid = 0;

		while (l < r) {
			mid = l + ((r - l) / 2);
			if (customfunction.f(i, mid) <= z) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		if (customfunction.f(i, l - 1) != z || (l - 1) <= 0)
			continue;
		result.emplace_back(vector<int>({i, l - 1}));
	}
	return result;
}
