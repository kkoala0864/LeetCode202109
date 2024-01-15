#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

vector<int> Solution::beautifulIndices(string s, string a, string b, int k) {
	vector<int> aIdx, bIdx;

	for (int i = 0 ; i <= (int)(s.size() - a.size()) ; ++i) {
		if (s[i] != a[0]) continue;
		if (s.substr(i, a.size()) == a) aIdx.emplace_back(i);
	}

	for (int i = 0 ; i <= (int)(s.size() - b.size()) ; ++i) {
		if (s[i] != b[0]) continue;
		if (s.substr(i, b.size()) == b) bIdx.emplace_back(i);
	}
	vector<int> result;
	for (const auto& ai : aIdx) {
		auto bi = lower_bound(bIdx.begin(), bIdx.end(), (ai - k));
		if (bi == bIdx.end()) continue;
		if (*bi <= (ai + k)) result.emplace_back(ai);
	}
	return result;
}
