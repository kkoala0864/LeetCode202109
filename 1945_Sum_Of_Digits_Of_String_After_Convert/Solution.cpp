#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

void convert(string& str) {
	int sum = 0;
	for (const auto& c : str) {
		sum += (c-'0');
	}
	str = to_string(sum);
}

int Solution::getLucky(string s, int k) {
	string str;
	for (const auto& c : s) str += to_string(c - 'a' + 1);

	for (int i = 0 ; i < k ; ++i) {
		convert(str);
	}
	return stoi(str);
}
