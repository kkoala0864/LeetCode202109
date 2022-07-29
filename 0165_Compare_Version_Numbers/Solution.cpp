#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

void parse(string& s, vector<int>& v) {
	string local("");
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] != '.') {
			local.push_back(s[i]);
		} else {
			v.emplace_back(stoi(local));
			local = "";
		}
	}
	if (local != "") v.emplace_back(stoi(local));
}

int Solution::compareVersion(string version1, string version2) {
	vector<int> v1, v2;
	string local;
	parse(version1, v1);
	parse(version2, v2);

	int size = max(v1.size(), v2.size());
	for (int i = 0 ; i < size ; ++i) {
		int val1 = i >= v1.size() ? 0 : v1[i];
		int val2 = i >= v2.size() ? 0 : v2[i];
		if (val1 > val2) return 1;
		else if (val1 < val2) return -1;
	}
	return 0;
}
