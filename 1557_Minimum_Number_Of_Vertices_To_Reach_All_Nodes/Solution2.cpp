#include <Solution.h>
#include <iostream>

vector<int> Solution::findSmallestSetOfVertices2(int n, vector<vector<int>>& edges) {
	vector<int> id(n, 0);
	for (const auto& e : edges) ++id[e[1]];
	vector<int> result;
	for (int i = 0 ; i < n ; ++i) if (id[i] == 0) result.emplace_back(i);
	return result;
}
