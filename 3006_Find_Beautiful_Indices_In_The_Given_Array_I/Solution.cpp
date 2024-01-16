#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;
void getNext(const string& a, vector<int>& v) {
	int prev = 0;
	int cur = 1;
	v.emplace_back(0);

	while (cur < a.size()) {
		if (a[prev] == a[cur]) {
			++prev;
			++cur;
			v.emplace_back(prev);
		} else {
			if (prev == 0) {
				++cur;
				v.emplace_back(0);
			} else prev = v[prev - 1];
		}
	}
}

void getIdx(const string& s, const string& a, const vector<int>& next, vector<int>& idx) {
	int sIdx = 0;
	int aIdx = 0;
	while (sIdx < s.size()) {
		if (s[sIdx] == a[aIdx]) {
			++aIdx;
			++sIdx;
			if (aIdx == a.size()) {
				idx.emplace_back(sIdx - a.size());
				aIdx = 0;
			}
		} else {
			if (aIdx == 0) ++sIdx;
			else aIdx = next[aIdx - 1];
		}
	}
}

vector<int> Solution::beautifulIndices(string s, string a, string b, int k) {
	vector<int> next1, next2;
	getNext(a, next1);
	getNext(b, next2);
	vector<int> aIdx, bIdx;
	getIdx(s, a, next1, aIdx);
	getIdx(s, b, next2, bIdx);
	vector<int> result;
	for (const auto& ai : aIdx) {
		auto bi = lower_bound(bIdx.begin(), bIdx.end(), (ai - k));
		if (bi == bIdx.end()) continue;
		if (*bi <= (ai + k)) result.emplace_back(ai);
	}
	return result;
}
