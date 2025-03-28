#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

bool Solution::areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs) {
	unordered_map<string, unordered_set<string>> sm;
	for (const auto &v : similarPairs) {
		sm[v[0]].emplace(v[1]);
		sm[v[1]].emplace(v[0]);
	}

	if (sentence1.size() != sentence2.size())
		return false;

	int size = sentence1.size();
	for (int i = 0; i < size; ++i) {
		if (sentence1[i] == sentence2[i])
			continue;
		if (sm[sentence1[i]].count(sentence2[i]) == 0)
			return false;
	}
	return true;
}
