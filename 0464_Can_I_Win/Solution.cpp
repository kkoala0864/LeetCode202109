#include <Solution.h>

bool dfs(int rest, int maxChoosableInteger, int mask, unordered_map<int, bool>& cache) {
	if (rest <= 0) return cache[mask] = false;
	if (cache.count(mask)) return cache[mask];

	if (rest <= maxChoosableInteger) {
		for (int i = 1 ; i <= maxChoosableInteger ; ++i) {
			if ((1 << i) & mask) continue;
			if (i >= rest) {
				return cache[mask] = true;
			}
		}
		return cache[mask] = false;
	}

	for (int i = 1 ; i <= maxChoosableInteger ; ++i) {
		if ((1 << i) & mask) continue;
		if (!dfs(rest - i, maxChoosableInteger, (1 << i) | mask, cache)) return cache[mask] = true;
	}
	return cache[mask] = false;
}

bool Solution::canIWin(int maxChoosableInteger, int desiredTotal) {
	if (desiredTotal == 0) return true;
	if (((maxChoosableInteger + 1) * maxChoosableInteger / 2) < desiredTotal) return false;
	unordered_map<int, bool> cache;
	return dfs(desiredTotal, maxChoosableInteger, 0, cache);
}
