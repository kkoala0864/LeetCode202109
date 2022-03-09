#include <Solution.h>
#include <iostream>

int Solution::repeatedStringMatch2(string a, string b) {
	int cnt = 1;
	string concate(a);
	while (concate.size() < b.size()) {
		++cnt;
		concate += a;
	}
	if (concate.find(b) != std::string::npos) {
		return cnt;
	}
	concate += a;
	if (concate.find(b) != std::string::npos) {
		return cnt + 1;
	}
	return -1;
}
