#include <Solution.h>

int Solution::minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
	int psize = languages.size();
	vector<unordered_set<int>> ls(n);

	for (int i = 0 ; i < psize ; ++i) {
		for (const auto& l : languages[i]) {
			ls[l-1].emplace(i);
		}
	}

	vector<vector<int>> noCommon;
	for (const auto& f : friendships) {
		bool find = false;
		for (int i = 0 ; i < n ; ++i) {
			if (ls[i].count(f[0]-1) && ls[i].count(f[1]-1)) {
				find = true;
				break;
			}
		}
		if (!find) noCommon.emplace_back(f);
	}

	int result = INT_MAX;
	for (int i = 0 ; i < n ; ++i) {
		int cnt = 0;
		for (const auto& c : noCommon) {
			if (ls[i].count(c[0]-1) == 0) {
				ls[i].emplace(c[0]-1);
				++cnt;
			}
			if (ls[i].count(c[1]-1) == 0) {
				ls[i].emplace(c[1]-1);
				++cnt;
			}
			if (cnt >= result) break;
		}
		result = min(result, cnt);
	}

	return result;
}
