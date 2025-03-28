#include <Solution.h>
#include <iostream>
#include <string>
#include <unordered_set>

using std::string;
using std::to_string;
using std::unordered_set;

bool Solution::confusingNumber(int n) {
	string val = to_string(n);
	unordered_set<char> invalid = {'2', '3', '4', '5', '7'};

	for (int i = 0; i < val.size(); ++i) {
		if (invalid.count(val[i]))
			return false;

		if (val[i] == '6') {
			val[i] = '9';
		} else if (val[i] == '9') {
			val[i] = '6';
		}
	}
	while (!val.empty() && val.back() == '0') {
		val.pop_back();
	}

	reverse(val.begin(), val.end());

	return n != stoi(val);
}
