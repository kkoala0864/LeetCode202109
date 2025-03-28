#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

char getChar(const string &s, int idx) {
	cout << idx << endl;
	string cs = {'a', 'b', 'c'};
	if (s.empty())
		return cs[idx];

	int j = -1;
	for (int i = 0; i < 3; ++i) {
		if (s.back() == cs[i])
			continue;
		++j;
		if (j == idx)
			return cs[i];
	}
	return 'd';
}

string Solution::getHappyString(int n, int k) {
	string result;
	--k;
	int base = 1 << (n - 1);
	if (k >= (base * 3))
		return "";

	for (int i = 0; i < n - 1; ++i) {
		result.push_back(getChar(result, k / base));
		k %= base;
		base = base >> 1;
	}
	result.push_back(getChar(result, k / base));
	return result;
}
