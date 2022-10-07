#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<vector<string>> Solution::groupStrings2(vector<string>& strings) {
	unordered_map<string, vector<string>> uMap;

	for (auto& s : strings) {
		int diff = s[0] - 'a';
		string key;
		for (const auto& c : s) {
			key.push_back(((c-diff+26) % 26));
		}
		uMap[key].emplace_back(s);
	}

	vector<vector<string>> result;
	for (const auto& e : uMap) {
		result.emplace_back(e.second);
	}
	return result;
}
