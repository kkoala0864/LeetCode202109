#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::cout;
using std::endl;

int Solution::findChampion(int n, vector<vector<int>>& edges) {
	vector<int> id(n, 0);

	for (const auto& e : edges) {
		++id[e[1]];
	}

	int result = 0;
	int cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		if (id[i] == 0) {
			++cnt;
			result = i;
		}
	}

	return cnt > 1 ? -1 : result;

}
