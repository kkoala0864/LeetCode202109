#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::canConstruct(string ransomNote, string magazine) {
	vector<int> cnt(26,0);
	for (const auto& v : magazine) ++cnt[v-'a'];

	for (const auto& v : ransomNote) {
		if (cnt[v-'a'] == 0) return false;
		else --cnt[v-'a'];
	}

	return true;
}
