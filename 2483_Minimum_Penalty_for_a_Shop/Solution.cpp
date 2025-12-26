#include <Solution.h>

int Solution::bestClosingTime(string customers) {
	int tY = 0;
	int tN = 0;

	for (const auto& c : customers) {
		if (c == 'Y') ++tY;
		else ++tN;
	}

	int minP = tY;
	int result = 0;
	int cY = 0;
	for (int i = 0 ; i < customers.size() ; ++i) {
		if (customers[i] == 'Y') ++cY;
		int cN = (i + 1) - cY;
		int p = tY - cY + ((i + 1) - cY);
		if (p < minP) {
			minP = p;
			result = i + 1;
		}
	}
	return result;
}
