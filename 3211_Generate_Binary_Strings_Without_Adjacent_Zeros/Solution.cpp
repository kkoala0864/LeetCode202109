#include <Solution.h>
#include <iostream>

vector<string> Solution::validStrings(int n) {
	vector<string> result;
	result.emplace_back("0");
	result.emplace_back("1");

	for (int i = 1; i < n; ++i) {
		vector<string> tmp;
		for (const auto &v : result) {
			if (v.back() == '0') {
				string s = v;
				s.push_back('1');
				tmp.emplace_back(s);
			} else {
				string s = v;
				s.push_back('1');
				tmp.emplace_back(s);
				s = v;
				s.push_back('0');
				tmp.emplace_back(s);
			}
		}
		result = move(tmp);
	}
	return result;
}
