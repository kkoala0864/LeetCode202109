#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::canBeValid(string s, string locked) {
	int size = s.size();
	if (size & 1) return false;
	int offset = 0;

	for (int i = 0 ; i < size ; ++i) {
		if (locked[i] == '0' || s[i] == '(') ++offset;
		else --offset;
		if (offset < 0) return false;
	}

	offset = 0;
	for (int i = size - 1 ; i >= 0 ; --i) {
		if (locked[i] == '0' || s[i] == ')') ++offset;
		else --offset;
		if (offset < 0) return false;
	}
	return true;
}
