#include <Solution.h>

// 1 0
// 2 3 1

int findDepth(int v) {
	int K = 1;
	while ((1 << K) <= v) {
		++K;
	}
	return K - 1;
}

int findLCA(int a, int b) {
	int depA = findDepth(a);
	int depB = findDepth(b);
	if (depA != depB) {
		if (depA > depB) {
			a >>= (depA - depB);
		} else {
			b >>= (depB - depA);
		}
	}

	if (a == b) return a;

	while (a != b) {
		a >>= 1;
		b >>= 1;
	}
	return a;
}
vector<int> Solution::cycleLengthQueries(int n, vector<vector<int>>& queries) {
	vector<int> result;
	for (const auto& q : queries) {
		int lca = findLCA(q[0], q[1]);
		result.emplace_back(findDepth(q[0]) + findDepth(q[1]) - 2 * findDepth(lca) + 1);
	}
	return result;
}
