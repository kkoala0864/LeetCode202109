#include <Solution.h>

void parse(const string& version, vector<int>& r) {
	string tmp;
	for (const auto& v : version) {
		if (v == '.') {
			r.emplace_back(stoi(tmp));
			tmp = "";
		} else {
			tmp.push_back(v);
		}
	}
	if (!tmp.empty()) {
		r.emplace_back(stoi(tmp));
	}
	return;
}

int Solution::compareVersion(string version1, string version2) {
	vector<int> r1, r2;
	parse(version1, r1);
	parse(version2, r2);
	int size = max(r1.size(), r2.size());

	for (int i = 0 ; i < size ; ++i) {
		int v1 = i < r1.size() ? r1[i] : 0;
		int v2 = i < r2.size() ? r2[i] : 0;
		if (v1 == v2) continue;
		return v1 < v2 ? -1 : 1;
	}
	return 0;
}
