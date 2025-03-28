#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool check(vector<int> &cnt) {
	string vowel = "aeiou";
	for (const auto &c : vowel) {
		if (cnt[c - 'a'] == 0)
			return false;
	}
	return true;
}

int cntVowel(vector<int> &cnt) {
	string vowel = "aeiou";
	int ret = 0;
	for (const auto &c : vowel) {
		ret += cnt[c - 'a'];
	}
	return ret;
}

int Solution::countOfSubstrings(string word, int k) {
	int result = 0;
	for (int sz = k + 5; sz <= word.size(); ++sz) {
		vector<int> cnt(26, 0);

		int l = 0;
		for (int i = 0; i < word.size(); ++i) {
			++cnt[word[i] - 'a'];
			if (i >= sz) {
				--cnt[word[l] - 'a'];
				++l;
			}
			if (i >= sz - 1) {
				if (check(cnt) && (sz - cntVowel(cnt)) == k) {
					++result;
				}
			}
		}
	}
	return result;
}
