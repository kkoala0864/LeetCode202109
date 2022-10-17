#include <Solution.h>
#include <iostream>

bool Solution::checkIfPangram(string sentence) {
	int mask = (1 << 26) - 1;
	int val = 0;
	for (const auto& c : sentence) {
		val |= 1 << (c-'a');
		if (val == mask) return true;
	}
	return false;
}
