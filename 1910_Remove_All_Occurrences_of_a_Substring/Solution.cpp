#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

string Solution::removeOccurrences(string s, string part) {
	auto idx = s.find(part);
	string tmp;
	while (idx != std::string::npos) {
		if (idx != 0) {
			tmp = s.substr(0, idx);
		}
		tmp += s.substr(idx + part.size());
		s = move(tmp);
		idx = s.find(part);
	}
	return s;
}
