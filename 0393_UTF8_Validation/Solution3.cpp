#include <Solution.h>
#include <iostream>

bool Solution::validUtf83(vector<int>& data) {
	int idx = 0;
	while (idx < data.size()) {
		int cnt = 0;
		for (int i = 7 ; i >= 3 ; --i) {
			if (data[idx] & (1 << i)) ++cnt;
			else break;
		}
		if (cnt == 1 || cnt > 4) return false;
		if ((cnt + idx) > data.size()) return false;
		for (int i = idx + 1 ; i < (idx + cnt) ; ++i) {
			if (data[i] >> 6 != 2) return false;
		}
		idx += cnt == 0 ? 1 : cnt;
	}
	return true;
}
