#include <Solution.h>

int Solution::maxDistance(string s, int k) {
	unordered_map<char, int> idxs = {{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3}};
	vector<int> cnt(4, 0);
	vector<int> fac = {1, -1, 1, -1};
	int ox = 0;
	int oy = 0;
	int result = 0;

	for (const auto& c : s) {
		++cnt[idxs[c]];
		if (c == 'W' || c == 'E') {
			ox += fac[idxs[c]];
		} else {
			oy += fac[idxs[c]];
		}
		int xo = ox > 0 ? cnt[3] : cnt[2];
		int yo = oy > 0 ? cnt[1] : cnt[0];
		int opp = min(xo + yo, k);
		result = max(result, abs(ox) + abs(oy) + 2 * opp);
	}
	return result;
}
