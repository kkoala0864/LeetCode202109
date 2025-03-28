#include <Solution.h>
#include <iostream>

bool Solution::doesValidArrayExist(vector<int> &derived) {
	int v = 0;
	for (const auto &d : derived) {
		v = v ^ d;
	}
	return v == 0;
}
