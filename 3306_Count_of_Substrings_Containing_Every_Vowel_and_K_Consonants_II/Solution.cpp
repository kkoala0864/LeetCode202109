#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

long long Solution::countOfSubstrings(string word, int k) {
	long long result = 0;
	unordered_set<char> us = {'a', 'e', 'i', 'o', 'u'};
	unordered_map<char, int> um;
	int conCnt = 0;
	int j = 0;
	vector<int> cc(word.size(), 0);
	int cnt = 0;
	for (int i = word.size() - 1; i >= 0; --i) {
		if (us.count(word[i]))
			++cnt;
		else
			cnt = 0;
		cc[i] = cnt;
	}

	for (int i = 0; i < word.size(); ++i) {
		while (j < word.size() && (um.size() < 5 || conCnt < k)) {
			if (us.count(word[j])) {
				++um[word[j]];
			} else {
				++conCnt;
			}
			++j;
		}

		if (um.size() == 5 && conCnt == k) {
			result += (1 + (j == word.size() ? 0 : cc[j]));
		}

		if (us.count(word[i])) {
			--um[word[i]];
			if (um[word[i]] == 0) {
				um.erase(word[i]);
			}
		} else {
			--conCnt;
		}
	}
	return result;
}
