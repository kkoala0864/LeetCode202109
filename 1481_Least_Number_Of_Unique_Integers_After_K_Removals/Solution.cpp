#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::sort;
using std::unordered_map;
using std::pair;

int Solution::findLeastNumOfUniqueInts(vector<int>& arr, int k) {
	unordered_map<int, int> m;
	for (const auto& v : arr) ++m[v];

	vector<pair<int, int>> list;
	for (const auto& e : m) {
		list.emplace_back(pair<int, int>(e.second, e.first));
	}
	sort(list.begin(), list.end(), std::greater<pair<int, int>>());

	while (!list.empty()) {
		if ((k - list.back().first) >= 0) {
			k -= list.back().first;
			list.pop_back();
		} else {
			break;
		}
	}
	return list.size();

}
