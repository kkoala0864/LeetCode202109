#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

int Solution::repeatedStringMatch(string a, string b) {
	int cnt = 1;
	string s(a);
	while (s.size() < b.size()) {
		s += a;
		++cnt;
	}
	if (s.find(b) != std::string::npos) return cnt;
	if ((s+a).find(b) != std::string::npos) return cnt+1;
	return -1;
}
