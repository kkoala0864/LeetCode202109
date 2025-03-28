#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<int> Solution::xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
	vector<int> preOR;

	int cur = 0;
	for (const auto &v : arr) {
		cur = cur ^ v;
		preOR.emplace_back(cur);
	}

	vector<int> result;
	for (const auto &q : queries) {
		int v = preOR[q[1]];
		if (q[0] > 0)
			v = v ^ preOR[q[0] - 1];
		result.emplace_back(v);
	}
	return result;
}
