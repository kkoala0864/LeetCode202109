#include <Solution.h>
#include <iostream>

int Solution::numberOfBeams(vector<string>& bank) {
	vector<int> cnt;

	for (int i = 0 ; i < bank.size() ; ++i) {
		int v = 0;
		for (const auto& c : bank[i]) {
			if (c == '1') {
				++v;
			}
		}
		if (v > 0) cnt.emplace_back(v);
	}
	if (cnt.size() < 2) return 0;
	int result = 0;
	for (int i = 0 ; i < cnt.size() - 1 ; ++i) {
		result += (cnt[i] * cnt[i+1]);
	}
	return result;
}
