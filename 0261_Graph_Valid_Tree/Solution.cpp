#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::validTree(int n, vector<vector<int>> &edges) {
	if (edges.size() < n - 1)
		return false;
	vector<int> edge(n, -1);

	for (const auto &iter : edges) {
		int v1 = iter[0];
		int v2 = iter[1];
		while (edge[v1] != -1)
			v1 = edge[v1];
		while (edge[v2] != -1)
			v2 = edge[v2];
		if (v1 == v2)
			return false;
		else
			edge[v2] = v1;
	}
	return true;
}
