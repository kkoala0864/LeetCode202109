#include <Solution.h>
#include <iostream>

bool dfs(int n, vector<bool> &check, int ri, vector<int> &result) {
	if (ri == result.size())
		return true;
	if (result[ri] != 0)
		return dfs(n, check, ri + 1, result);

	for (int i = n; i >= 1; --i) {
		if (check[i])
			continue;
		if (i != 1) {
			if ((ri + i) >= result.size() || result[ri + i] != 0)
				continue;
			result[ri + i] = i;
		}
		result[ri] = i;
		check[i] = true;
		if (dfs(n, check, ri + 1, result))
			return true;
		check[i] = false;
		result[ri] = 0;
		if (i != 1) {
			result[ri + i] = 0;
		}
	}
	return false;
}

vector<int> Solution::constructDistancedSequence(int n) {
	int size = 2 * n - 1;
	vector<int> result(size, 0);

	vector<bool> check(n, false);
	dfs(n, check, 0, result);
	return result;
}
