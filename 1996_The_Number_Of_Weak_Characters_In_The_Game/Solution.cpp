#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::max;
using std::sort;
using std::stack;

int Solution::numberOfWeakCharacters(vector<vector<int>> &properties) {
	auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
	};
	sort(properties.begin(), properties.end(), cmp);

	int result = 0;
	int maxDef = 0;
	for (int i = properties.size() - 1; i >= 0; --i) {
		if (properties[i][1] < maxDef) {
			++result;
		}
		maxDef = max(maxDef, properties[i][1]);
	}
	return result;
}
