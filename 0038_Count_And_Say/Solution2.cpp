#include <Solution.h>
#include <iostream>
#include <vector>

using std::to_string;

// 1 => 1
// 2 => 11
// 3 => 21
// 4 => 1211
// 5 => 111221
// 6 => 312211

string Solution::countAndSay2(int n) {
	string val = "1";
	string tmpVal;
	for (int idx = 2 ; idx <= n ; ++idx) {
		for (int i = 0 ; i < val.size() ; ++i) {
			int cnt = 1;
			while (i < val.size() - 1 && val[i] == val[i+1]) {
				++cnt;
				++i;
			}
			tmpVal += to_string(cnt);
			tmpVal.push_back(val[i]);
		}
		val = move(tmpVal);
	}
	return val;
}
