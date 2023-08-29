#include <Solution.h>
#include <iostream>

int Solution::bestClosingTime(string customers) {
	int curP = 0;
	int result = 0;

	for (int i = 0 ; i < customers.size() ; ++i) {
		if (customers[i] == 'Y') {
			++curP;
		}
	}
	int minP = curP;

	for (int i = 0 ; i < customers.size() ; ++i) {
		if (customers[i] == 'Y') {
			--curP;
		} else {
			++curP;
		}
		if (minP > curP) {
			minP = curP;
			result = i + 1;
		}
	}
	return result;
}
