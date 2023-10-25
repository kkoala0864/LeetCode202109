#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::kthGrammar(int n, int k) {
	int base = k - 1;
	vector<int> idx;

	while (base > 0) {
		idx.emplace_back(base & 1);
		base = base >> 1;
	}

	int result = 0;
	while (!idx.empty()) {
		int v = idx.back();
		idx.pop_back();
		result = v == 0 ? result : result ^ 1;
	}
	return result;
}
