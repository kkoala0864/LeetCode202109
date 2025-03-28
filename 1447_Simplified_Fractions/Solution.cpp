#include <Solution.h>
#include <iostream>

using std::swap;
using std::to_string;

int getGCD(int i, int j) {
	if (i < j)
		swap(i, j);
	if (j == 0)
		return i;
	i %= j;
	return getGCD(j, i);
}

vector<string> Solution::simplifiedFractions(int n) {
	vector<string> result;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (getGCD(j, i) != 1)
				continue;
			result.emplace_back(to_string(j) + "/" + to_string(i));
		}
	}
	return result;
}
