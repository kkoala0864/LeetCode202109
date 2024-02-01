#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

// KMP algorithm
void getNexTable(const string& s, vector<int>& nt) {
	int pi = 0;
	int cur = 1;
	nt.emplace_back(0);

	while (cur < s.size()) {
		if (s[cur] == s[pi]) {
			++pi;
			++cur;
			nt.emplace_back(pi);
		} else {
			if (pi == 0) {
				++cur;
				nt.emplace_back(pi);
			} else {
				pi = nt[pi - 1];
			}
		}
	}
}

void getIdx(const string& h, const string& n, const vector<int>& nt, vector<int>& result) {
	int hi = 0;
	int ni = 0;
	while (hi < h.size()) {
		if (h[hi] == n[ni]) {
			++hi;
			++ni;
			if (ni == n.size()) {
				ni = 0;
				result.emplace_back(hi - n.size());
			}
		} else {
			if (ni == 0) ++hi;
			else ni = nt[ni - 1];
		}
	}
}

int Solution::strStr3(string haystack, string needle) {
	vector<int> nextTable;
	getNexTable(needle, nextTable);
	vector<int> result;
	getIdx(haystack, needle, nextTable, result);
	return result.empty() ? -1 : result[0];
}
