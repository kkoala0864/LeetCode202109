#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::sort;

vector<vector<string>> Solution::groupAnagrams2(vector<string>& strs) {
	unordered_map<string, vector<string>> group;
	vector<vector<string>> result;
	for (const auto& str : strs) {
		string tmp = str;
		sort(tmp.begin(), tmp.end());
		group[tmp].emplace_back(str);
	}
	for (const auto& iter : group) {
		result.emplace_back(iter.second);
	}
	return result;
}
