#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string sortStr2(const string& str) {
	vector<int> record(26, 0);
	for (const auto& iter : str) {
		++record[iter-'a'];
	}

	string result;
	for (int i = 0 ; i < 26 ; ++i) {
		if (record[i] > 0) result += string(record[i], i + 'a');
	}
	return result;
}

vector<vector<string>> Solution::groupAnagrams2(vector<string>& strs) {
	unordered_map<string, int> group;
	vector<vector<string>> result;
	for (const auto& str : strs) {
		string tmp = sortStr2(str);
		if (group.find(tmp) != group.end()) {
			result[group[tmp]].emplace_back(str);
		} else {
			result.push_back({str});
			group[tmp] = result.size() - 1;
		}
	}
	return result;
}
