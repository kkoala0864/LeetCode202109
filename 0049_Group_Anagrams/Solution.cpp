#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

string sortStr(const string &input) {
	vector<int> count(26, 0);

	for (const auto &iter : input)
		++count[iter - 'a'];

	string result;
	for (int i = 0; i < count.size(); ++i) {
		if (count[i] != 0)
			result += string(count[i], i + 'a');
	}
	return result;
}

vector<vector<string>> Solution::groupAnagrams(vector<string> &strs) {
	vector<vector<string>> result;
	unordered_map<string, vector<string>> map;

	for (const auto &iter : strs) {
		string countStr = sortStr(iter);
		map[countStr].emplace_back(iter);
	}

	for (const auto &iter : map) {
		result.emplace_back(iter.second);
	}
	return result;
}
