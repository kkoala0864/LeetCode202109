#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string Solution::findReplaceString2(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
	unordered_map<int, int> uMap;
	for (int i = 0 ; i < sources.size() ; ++i) {
		uMap[indices[i]] = i;
	}

	string result;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (uMap.find(i) != uMap.end()) {
			int size = sources[uMap[i]].size();
			if ((i + size - 1) < s.size()) {
				string cmpStr = s.substr(i, size);
				if (cmpStr == sources[uMap[i]]) {
					result += targets[uMap[i]];
					i += (size - 1);
					continue;
				}
			}
		}
		result.push_back(s[i]);
	}
	return result;
}
