#include <Solution.h>
#include <iostream>

vector<int> Solution::findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
	vector<int> id(n, 0);

	vector<int> result;
	for (const auto &e : edges)
		++id[e[1]];

	for (int i = 0; i < n; ++i) {
		if (id[i] == 0)
			result.emplace_back(i);
	}
	return result;
}
