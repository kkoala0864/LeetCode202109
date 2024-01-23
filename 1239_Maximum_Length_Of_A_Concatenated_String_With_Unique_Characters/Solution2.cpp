#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int getMask(const string& s) {
	int result = 0;
	for (const auto& c : s) result |= (1 << (c - 'a'));
	return result;
}

int getOne(int m) {
	int result = 0;
	while (m) {
		++result;
		m &= (m-1);
	}
	return result;
}

void dfs2(vector<string>& arr, int idx, int& result, int mask, vector<int>& mm) {
	for (int i = idx + 1 ; i < arr.size() ; ++i) {
		if (arr[i].size() != getOne(mm[i])) continue;
		if ((mask & mm[i]) > 0) continue;
		int nm = mask | mm[i];
		result = max(result, getOne(nm));
		dfs2(arr, i, result, nm, mm);
	}
}

int Solution::maxLength2(vector<string>& arr) {
	vector<int> mm;
	int result = 0;
	for (const auto& s : arr) {
		mm.emplace_back(getMask(s));
	}
	dfs2(arr, -1, result, 0, mm);
	return result;
}
