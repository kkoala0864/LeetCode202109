#include <Solution.h>
#include <iostream>

int Solution::countStudents(vector<int>& students, vector<int>& sandwiches) {
	int s0 = 0, s1 = 0;
	for (const auto& s : students) {
		if (s == 1) ++s1;
		else ++s0;
	}

	for (const auto& s : sandwiches) {
		if (s == 0) {
			if (s0 > 0) --s0;
			else break;
		} else {
			if (s1 > 0) --s1;
			else break;
		}
	}
	return s0 + s1;
}
