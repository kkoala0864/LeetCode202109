#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string Solution::findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
	unordered_map<int, string> sMap;
	unordered_map<int, string> tMap;
	for (int i = 0; i < indices.size(); ++i) {
		sMap[indices[i]] = sources[i];
		tMap[indices[i]] = targets[i];
	}

	string result;
	for (int i = 0; i < s.size(); ++i) {
		if (sMap.find(i) != sMap.end()) {
			string sub = s.substr(i, sMap[i].size());
			if (sub == sMap[i]) {
				result += tMap[i];
				i += (sMap[i].size() - 1);
			} else {
				result.push_back(s[i]);
			}
		} else {
			result.push_back(s[i]);
		}
	}
	return result;
}
