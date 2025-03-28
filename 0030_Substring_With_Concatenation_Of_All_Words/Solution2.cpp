#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void check(const string &s, unordered_map<string, int> wMap, int start, int wordCnt, int size, vector<int> &result) {
	int total = (wordCnt - 1) * size;
	for (int i = start; i < s.size(); i += size) {
		string cur = s.substr(i, size);
		while (wMap.find(cur) == wMap.end() || wMap[cur] == 0) {
			string startS = s.substr(start, size);
			++wMap[startS];
			start += size;
		}
		--wMap[cur];
		if ((i - start) == total)
			result.emplace_back(start);
	}
}

vector<int> Solution::findSubstring2(string s, vector<string> &words) {
	unordered_map<string, int> wMap;

	int size = words.back().size();
	int wordCnt = words.size();
	vector<int> result;

	for (const auto &w : words)
		++wMap[w];

	for (int i = 0; i < size; ++i)
		check(s, wMap, i, wordCnt, size, result);
	return result;
}
