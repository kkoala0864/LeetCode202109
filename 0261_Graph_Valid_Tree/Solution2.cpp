#include <Solution.h>
#include <iostream>

bool Solution::validTree2(int n, vector<vector<int>> &edges) {
	if (edges.size() < n - 1)
		return false;
	vector<int> relation(n, -1);
	for (int i = 0; i < relation.size(); ++i) {
		relation[i] = i;
	}

	for (const auto &edge : edges) {
		int x = edge[0];
		int y = edge[1];
		while (x != relation[x])
			x = relation[x];
		while (y != relation[y])
			y = relation[y];
		if (x == y)
			return false;
		relation[x] = y;
	}

	return true;
}
