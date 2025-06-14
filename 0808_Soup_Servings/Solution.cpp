#include <Solution.h>


double dfs(int a_cap, int b_cap, unordered_map<int, unordered_map<int, double>>& cache) {
	if (cache.count(a_cap) && cache[a_cap].count(b_cap)) return cache[a_cap][b_cap];

	if (a_cap > 0 && b_cap <= 0) return 0;
	if (a_cap <= 0) {
		if (b_cap > 0) return 1;
		else {
			if (a_cap == b_cap) return 0.5;
			else return b_cap > a_cap ? 1 : 0;
		}
	}

	vector<vector<int>> soup_service = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

	for (const auto& ss : soup_service) {
		cache[a_cap][b_cap] += (0.25 * dfs(a_cap - ss[0], b_cap - ss[1], cache));
	}
	return cache[a_cap][b_cap];
}

double Solution::soupServings(int n) {
	n = (n + 24) / 25;
	if (n > 500) return 1;
	unordered_map<int, unordered_map<int, double>> cache;

	return dfs(n, n, cache);
}
