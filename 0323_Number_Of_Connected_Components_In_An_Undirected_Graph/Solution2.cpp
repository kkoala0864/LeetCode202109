#include <Solution.h>
#include <iostream>

int Solution::countComponents2(int n, vector<vector<int>> &edges) {
	vector<int> relation(n, 0);
	for (int i = 0; i < n; ++i) {
		relation[i] = i;
	}

	for (const auto &edge : edges) {
		int x = edge[0];
		int y = edge[1];

		while (x != relation[x])
			x = relation[x];
		while (y != relation[y])
			y = relation[y];
		if (x != y) {
			--n;
			relation[x] = y;
		}
	}
	return n;
}
