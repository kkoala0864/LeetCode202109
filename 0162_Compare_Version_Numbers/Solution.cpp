#include <Solution.h>
#include <iostream>

int getVersion(int& idx, const string& version) {
	if (idx >= version.size()) {
		return 0;
	}
	bool noLeading = false;
	string result = "";
	while (idx < version.size() && version[idx] != '.') {
		if (version[idx] != '0') noLeading = true;
		if (noLeading) result.push_back(version[idx]);
		++idx;
	}
	++idx;
	return result == "" ? 0 : stoi(result);
}

int Solution::compareVersion(string version1, string version2) {
	int idx1 = 0, idx2 = 0;
	while (idx1 < version1.size() || idx2 < version2.size()) {
		int v1 = getVersion(idx1, version1);
		int v2 = getVersion(idx2, version2);
		if (v1 == v2) continue;
		else if (v1 > v2) return 1;
		else return -1;
	}
	return 0;
}
