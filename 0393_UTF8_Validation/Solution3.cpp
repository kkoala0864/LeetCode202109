#include <Solution.h>
#include <iostream>

bool Solution::validUtf83(vector<int> &data) {
	for (int i = 0; i < data.size(); ++i) {
		int prefixOne = 0;
		int prefixIdx = 7;
		while (prefixIdx >= 0 && (data[i] >> prefixIdx) & 1) {
			++prefixOne;
			--prefixIdx;
		}
		if (prefixOne == 0)
			continue;
		if (prefixOne == 1 || prefixOne > 4)
			return false;
		if (i + prefixOne > data.size())
			return false;
		for (int j = 1; j < prefixOne; ++j) {
			if (((data[i + j] >> 6) & 3) != 2)
				return false;
		}
		i += (prefixOne - 1);
	}
	return true;
}
