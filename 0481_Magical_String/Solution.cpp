#include <Solution.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int Solution::magicalString(int n) {
	string s = "122";
	int cnt = 3;
	int si = 2;

	while (cnt < n) {
		int size = s[si] - '0';
		s += string(size, s.back() == '1' ? '2' : '1');
		cnt += (size * (s.back() == '1' ? 1 : 2));
		++si;
	}
	cnt = 0;
	int result = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		cnt += (s[i] - '0');
		if ((i & 1) == 0) result += (s[i] - '0');
		if (cnt == n) break;
		if (cnt > n) {
			if ((i & 1) == 0) --result;
			break;
		}
	}
	return result;
}
