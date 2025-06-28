#include <Solution.h>

// min-max
int dfs(int idx, int M, vector<int>& piles, vector<int>& postfix, vector<unordered_map<int, int>>& cache) {
	if (idx >= piles.size()) return 0;
	if (cache[idx].count(M)) return cache[idx][M];
	int pre = 0;

	if (piles.size() <= (idx + (2 * M))) {
		return cache[idx][M] = postfix[idx];
	}
	for (int x = 1 ; x <= (2 * M) ; ++x) {
		int pi = idx + x - 1;
		pre += piles[pi];
		cache[idx][M] = max(cache[idx][M], pre + postfix[pi + 1] - dfs(idx + x, max(M, x), piles, postfix, cache));
	}
	return cache[idx][M];
}

int Solution::stoneGameII(vector<int>& piles) {
	int size = piles.size();
	vector<int> postfix(size + 1, 0);
	vector<unordered_map<int, int>> cache(piles.size(), unordered_map<int, int>());
	for (int i = piles.size() - 1 ; i >= 0 ; --i) {
		postfix[i] = postfix[i + 1] + piles[i];
	}
	return dfs(0, 1, piles, postfix, cache);
}
