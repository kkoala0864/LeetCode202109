#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string Solution::findReplaceString2(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
	string result("");
	int idx = 0;
	unordered_map<int, int> uMap;
	for (int i = 0 ; i < indices.size() ; ++i) {
		size_t sz = sources[i].size();
		if (s.substr(indices[i], sz) == sources[i]) {
			uMap[indices[i]] = i;;
		}
	}

	while (idx < s.size()) {
		if (uMap.find(idx) != uMap.end()) {
			size_t sz = sources[uMap[idx]].size();
			result += targets[uMap[idx]];
			idx += (sz - 1);
		} else {
			result.push_back(s[idx]);
		}
		++idx;
	}
	return result;
}
