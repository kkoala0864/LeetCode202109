#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::vector;

bool checkVowel(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

int Solution::beautifulSubstrings(string s, int k) {
	unordered_map<int, vector<pair<int, int>>> m;

	int vCnt = 0;
	int cCnt = 0;
	int result = 0;
	for (const auto &c : s) {
		if (checkVowel(c))
			++vCnt;
		else
			++cCnt;

		int diff = vCnt - cCnt;
		if (diff == 0) {
			if ((vCnt * cCnt) % k == 0)
				++result;
		}
		if (m.count(diff) > 0) {
			for (const auto &p : m[diff]) {
				int v = (vCnt - p.first) * (cCnt - p.second);
				if (v % k == 0) {
					++result;
				}
			}
		}
		m[diff].emplace_back(pair<int, int>(vCnt, cCnt));
	}
	return result;
}
