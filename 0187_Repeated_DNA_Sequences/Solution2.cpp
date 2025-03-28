#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<string> Solution::findRepeatedDnaSequences2(string s) {
	vector<string> result;
	if (s.size() < 10)
		return result;
	unordered_map<string, int> map;
	for (int i = 0; i < s.size() - 9; ++i) {
		string sub = s.substr(i, 10);
		++map[sub];
		if (map[sub] == 2)
			result.emplace_back(sub);
	}
	return result;
}
