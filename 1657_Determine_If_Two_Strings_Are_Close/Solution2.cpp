#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool Solution::closeStrings2(string word1, string word2) {
	vector<int> cnt1(26, 0), cnt2(26, 0);
	if (word1.size() != word2.size()) return false;

	for (int i = 0 ; i < word1.size() ; ++i) {
		++cnt1[word1[i]-'a'];
		++cnt2[word2[i]-'a'];
	}

	unordered_map<int, int> m;
	vector<int> check(26, 0);

	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt1[i] > 0) ++check[i];
		if (cnt2[i] > 0) --check[i];
		++m[cnt1[i]];
		--m[cnt2[i]];
	}
	for (const auto& e : m) {
		if (e.second != 0) return false;
	}
	for (const auto& v : check) {
		if (v != 0) return false;
	}
	return true;
}
