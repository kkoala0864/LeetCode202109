#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::max;
using std::unordered_set;

int getMaxUnique(const string& s) {
	vector<bool> map(26, 0);
	int maxUnique = 0;
	for (const auto& iter : s) {
		if (!map[iter-'a']) {
			++maxUnique;
			map[iter-'a'] = true;
		}
	}
	return maxUnique;
}

int Solution::longestSubstring(string s, int k) {
	int MaxUnique = getMaxUnique(s);
	int result = 0;

	for (int curUni = 1 ; curUni <= MaxUnique ; ++curUni) {
		vector<int> count = vector<int>(26, 0);
		int start = 0, end = 0, unique = 0, countAtLeastK = 0;
		while (end < s.size()) {
			if (unique <= curUni) {
				int idx = s[end] - 'a';
				if (count[idx] == 0) ++unique;
				++count[idx];
				if (count[idx] == k) ++countAtLeastK;
				++end;
			} else {
				int idx = s[start] - 'a';
				if (count[idx] == k) --countAtLeastK;
				--count[idx];
				if (count[idx] == 0) --unique;
				++start;
			}
			if (unique == curUni && unique == countAtLeastK) {
				result = max(result, end - start);
			}
		}
	}
	return result;
}
/*
int Solution::longestSubstring(string s, int k) {
	vector<int> count(26, 0);
	unordered_set<char> lessK;
	int end = 0;
	int result = 0;
	while (end < s.size()) {
		++count[s[end]-'a'];
		if (count[s[end]-'a'] >= k) {
			if (lessK.find(s[end]) != lessK.end()) {
				lessK.erase(s[end]);
			}
			if (lessK.empty()) {
				result = max(result, end + 1);
			} else {
				unordered_set<char> check = lessK;
				vector<int> checkCount = count;
				int iter = 0;
				while (iter < end) {
					--checkCount[s[iter]-'a'];
					if (checkCount[s[iter]-'a'] == 0) {
						check.erase(s[iter]);
					} else if (checkCount[s[iter] - 'a'] < k) {
						check.emplace(s[iter]);
					}
					++iter;
					if (check.empty()) {
						result = max(result, end - iter + 1);
						break;
					}
				}
			}
		} else {
			lessK.emplace(s[end]);
		}
		++end;
	}
	return result;
}*/
