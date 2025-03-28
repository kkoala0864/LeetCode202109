#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::to_string;

void ParseNum(string &local, vector<string> &result) {
	int mins = 0;
	int base = 1;
	for (int i = 9; i >= 4; --i) {
		if (local[i] == '1')
			mins += base;
		base = base << 1;
	}
	if (mins >= 60)
		return;
	int hrs = 0;
	base = 1;
	for (int i = 3; i >= 0; --i) {
		if (local[i] == '1')
			hrs += base;
		base = base << 1;
	}
	if (hrs >= 12)
		return;
	string tmp = to_string(hrs) + ":" + (mins < 10 ? "0" + to_string(mins) : to_string(mins));
	result.emplace_back(tmp);
}

void dfs(int cnt, int total, string &local, vector<string> &result) {
	if (total == 0) {
		ParseNum(local, result);
		return;
	}

	for (int i = cnt; i < (10 - total + 1); ++i) {
		local[i] = '1';
		dfs(i + 1, total - 1, local, result);
		local[i] = '0';
	}
}

vector<string> Solution::readBinaryWatch(int turnedOn) {
	vector<string> result;
	string local("0000000000");
	dfs(0, min(10, turnedOn), local, result);
	return result;
}
