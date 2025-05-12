#include <Solution.h>

int check(vector<int>& cnt) {
	int diffCnt = 0;
	int minCnt = INT_MAX;

	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] == 0) continue;
		++diffCnt;
		minCnt = min(minCnt, cnt[i]);
	}
	if (diffCnt == 1) return true;
	return diffCnt == 2 && minCnt == 1;
}

int getLimit(vector<int>& wCnt, vector<int>& cnt) {
	int maxCnt = 0;
	int ret;

	for (int i = 0 ; i < 26 ; ++i) {
		if (wCnt[i] == 0) continue;
		if (maxCnt < wCnt[i]) {
			maxCnt = wCnt[i];
			ret = cnt[i];
		} else if (maxCnt == wCnt[i]) {
			ret = max(ret, cnt[i]);
		}
	}
	return ret;
}

int Solution::maxRepOpt1(string text) {
	vector<int> cnt(26, 0);

	for (const auto& c : text) ++cnt[c-'a'];

	int l = 0;
	vector<int> wCnt(26, 0);

	int result = 0;
	for (int i = 0 ; i < text.size() ; ++i) {
		++wCnt[text[i]-'a'];

		while (l < i && !check(wCnt)) {
			--wCnt[text[l]-'a'];
			++l;
		}

		result = max(result, min(i - l + 1, getLimit(wCnt, cnt)));
	}
	return result;
}

