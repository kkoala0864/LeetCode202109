#include <Solution.h>
#include <iostream>

int Solution::findChampion(int n, vector<vector<int>>& edges) {
	vector<int> weakDegree(n, 0);

	for (const auto& e : edges) {
		++weakDegree[e[1]];
	}
	int result = -1;
	int cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		if (weakDegree[i] == 0) {
			++cnt;
			if (cnt > 1) return -1;
			result = i;
		}
	}
	return result;
}
