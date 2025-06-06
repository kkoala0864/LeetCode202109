#include <Solution.h>

vector<int> getLPS(const string& s) {
	vector<int> lps(s.size(), 0);

	for (int i = 1 ; i < s.size() ; ++i) {
		int idx = lps[i-1];
		while (idx > 0 && s[idx] != s[i]) {
			idx = lps[idx-1];
		}
		lps[i] = idx + (s[idx] == s[i]);
	}
	return lps;
}

vector<int> getIdx(const string& s, const string& a) {
	vector<int> lps = getLPS(a);

	vector<int> result;
	vector<int> k(s.size(), 0);
	k[0] = s[0] == a[0];
	if (k[0] == a.size()) {
		result.emplace_back(0);
	}
	for (int i = 1 ; i < s.size() ; ++i) {
		int idx = k[i-1];
		while (idx > 0 && a[idx] != s[i]) {
			idx = lps[idx-1];
		}
		k[i] = idx + (a[idx] == s[i]);
		if (k[i] == a.size()) {
			result.emplace_back(i - a.size() + 1);
		}
	}
	return result;
}

vector<int> Solution::beautifulIndices(string s, string a, string b, int k) {
	vector<int> aIdx = getIdx(s, a);
	if (a == b) return aIdx;

	vector<int> bIdx = getIdx(s, b);

	vector<int> result;

	for (const auto& ai : aIdx) {
		int idx = lower_bound(bIdx.begin(), bIdx.end(), max(0, ai - k)) - bIdx.begin();
		if (idx == bIdx.size() || bIdx[idx] > (ai + k)) continue;
		result.emplace_back(ai);
	}
	return result;
}
