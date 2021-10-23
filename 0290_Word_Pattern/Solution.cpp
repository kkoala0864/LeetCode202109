#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool Solution::wordPattern(string pattern, string s) {
	vector<vector<int>> pIdx(26, vector<int>());

	for (int i = 0 ; i < pattern.size() ; ++i) pIdx[pattern[i]-'a'].emplace_back(i);

	vector<string> split;
	unordered_map<string, vector<int>> sIdx;
	int start = 0;
	int iter = 0;
	while (iter < s.size()) {
		if (s[iter] != ' ') ++iter;
		else {
			string str = s.substr(start, iter-start);
			split.emplace_back(str);
			sIdx[str].emplace_back(split.size()-1);
			start = iter + 1;
			iter = start;
		}
	}
	if (start < s.size()) {
		string str = s.substr(start);
		split.emplace_back(str);
		sIdx[str].emplace_back(split.size()-1);
	}
	if (pattern.size() != split.size()) return false;

	for (const auto& pVec : pIdx) {
		if (!pVec.empty()) {
			string str = split[pVec[0]];
			if (sIdx[str].size() != pVec.size()) return false;
			for (int i = 0 ; i < sIdx[str].size() ; ++i) {
				if (sIdx[str][i] != pVec[i]) return false;
			}
		}
	}
	return true;
}
