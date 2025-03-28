#include <Solution.h>
#include <iostream>

string Solution::stringShift(string s, vector<vector<int>> &shift) {
	string result = s;
	int size = s.size();

	for (auto &sf : shift) {
		sf[1] %= size;
		int ls = sf[0] == 0 ? sf[1] : size - sf[1];
		int rs = size - ls;

		string l = result.substr(0, ls);
		string r = result.substr(ls);

		result = r + l;
	}
	return result;
}
