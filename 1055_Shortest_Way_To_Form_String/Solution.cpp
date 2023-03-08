#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::upper_bound;

int Solution::shortestWay(string source, string target) {
	vector<vector<int>> idxs(26, vector<int>());

	for (int i = 0 ; i < source.size() ; ++i) {
		idxs[source[i]-'a'].emplace_back(i);
	}


	int cur = source.size();
	int result = 0;

	for (const auto& c : target) {
		if (idxs[c-'a'].empty()) return -1;
		int ni = upper_bound(idxs[c-'a'].begin(), idxs[c-'a'].end(), cur) - idxs[c-'a'].begin();
		if (ni == idxs[c-'a'].size()) {
			++result;
			cur = idxs[c-'a'][0];
		} else {
			cur = idxs[c-'a'][ni];
		}
	}
	return result;
}
