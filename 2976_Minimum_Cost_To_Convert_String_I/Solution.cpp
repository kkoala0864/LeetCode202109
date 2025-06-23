#include <Solution.h>

long long Solution::minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
	vector<vector<long long>> minCost(26, vector<long long>(26, LLONG_MAX/2));

	for (int i = 0 ; i < 26 ; ++i) minCost[i][i] = 0;
	for (int i = 0 ; i < original.size() ; ++i) {
		int oi = original[i] - 'a';
		int ci = changed[i] - 'a';
		minCost[oi][ci] = min(minCost[oi][ci], (long long)cost[i]);
	}

	for (int k = 0 ; k < 26 ; ++k) {
		for (int i = 0 ; i < 26 ; ++i) {
			for (int j = 0 ; j < 26 ; ++j) {
				minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
			}
		}
	}
	long long result = 0;
	for (int i = 0 ; i < source.size() ; ++i) {
		int si = source[i] - 'a';
		int ti = target[i] - 'a';
		if (minCost[si][ti] == LLONG_MAX/2) return -1;
		result += minCost[si][ti];
	}
	return result;
}
