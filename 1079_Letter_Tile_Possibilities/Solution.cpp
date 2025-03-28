#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int dfs(vector<int> &cnt) {
	int local = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 0)
			continue;
		--cnt[i];
		++local;
		local += dfs(cnt);
		++cnt[i];
	}
	return local;
}

int Solution::numTilePossibilities(string tiles) {
	vector<int> cnt(26, 0);
	for (const auto &c : tiles)
		++cnt[c - 'A'];

	return dfs(cnt);
}
