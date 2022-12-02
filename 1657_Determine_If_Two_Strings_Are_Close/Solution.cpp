#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool Solution::closeStrings(string word1, string word2) {
	if (word1.size() != word2.size()) return false;
	vector<int> cnt1(26, 0), cnt2(26, 0);

	int size = word1.size();
	for (int i = 0 ; i < size ; ++i) {
		++cnt1[word1[i]-'a'];
		++cnt2[word2[i]-'a'];
	}
	unordered_map<int, int> m;
	int bit1 = 0, bit2 = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt1[i] > 0) {
			++m[cnt1[i]];
			bit1 |= 1 << i;
		}
	}
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt2[i] > 0) {
			bit2 |= 1 << i;
			--m[cnt2[i]];
		}
	}

	if (bit1 != bit2) return false;
	for (const auto& e : m) {
		if (e.second != 0) return false;
	}
	return true;
}
