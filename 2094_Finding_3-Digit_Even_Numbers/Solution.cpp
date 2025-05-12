#include <Solution.h>

vector<int> Solution::findEvenNumbers(vector<int>& digits) {
	vector<int> cnt(10, 0);

	for (const auto& v : digits) {
		++cnt[v];
	}

	vector<int> result;
	for (int i = 1 ; i < 10 ; ++i) {
		if (cnt[i] == 0) continue;
		--cnt[i];
		int v = i;
		for (int j = 0 ; j < 10 ; ++j) {
			if (cnt[j] == 0) continue;
			--cnt[j];
			v *= 10;
			v += j;
			for (int k = 0 ; k < 10 ; k += 2) {
				if (cnt[k] == 0) continue;
				--cnt[k];
				v *= 10;
				v += k;
				result.emplace_back(v);
				++cnt[k];
				v -= k;
				v /= 10;
			}
			v -= j;
			v /= 10;
			++cnt[j];
		}
		++cnt[i];
	}
	return result;
}
