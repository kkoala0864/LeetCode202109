#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<string> Solution::findRepeatedDnaSequences(string s) {
	if (s.size() < 10) return vector<string>();
	unordered_map<string, int> uMap;
	vector<string> result;
	for (int i = 0 ; i < s.size()-9 ; ++i) {
		string sub = s.substr(i, 10);
		++uMap[sub];
		if (uMap[sub] == 2) result.emplace_back(sub);
	}
	return result;
}
