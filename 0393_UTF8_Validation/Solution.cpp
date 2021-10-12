#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
bool Solution::validUtf8(vector<int>& data) {
	int i = 0;
	for (; i < data.size() ; ++i) {
		int cnt = 0;
		for (int j = 0 ; j < 5 ; ++j) {
			int mask = 1 << (7 - j);
			if (data[i] & mask) ++cnt;
			else break;
		}
		if (cnt == 0) continue;
		if (cnt == 1 || cnt > 4) return false;
		else {
			for (int j = 1 ; j < cnt ; ++j) {
				++i;
				if (i >= data.size()) return false;
				int number = data[i];
				if ((number >> 6) != 2) return false;
			}
		}
	}
	return true;
}
