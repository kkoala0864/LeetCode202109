#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::reportSpam(vector<string> &message, vector<string> &bannedWords) {
	unordered_set<string> ban;
	for (const auto &b : bannedWords)
		ban.emplace(b);
	int cnt = 0;

	for (const auto &m : message) {
		if (ban.count(m))
			return true;
	}
	return false;
}
