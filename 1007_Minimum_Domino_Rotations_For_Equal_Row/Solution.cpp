#include <Solution.h>

int Solution::minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
	int mask = (1 << 7) - 1;
	int size = tops.size();

	vector<int> topCnt(7, 0), bottomsCnt(7, 0);
	for (int i = 0 ; i < size ; ++i) {
		int v = 0;
		v = v | (1 << tops[i]);
		v = v | (1 << bottoms[i]);
		if (i > 0 && (v & mask) == 0) return -1;
		mask &= v;
		++topCnt[tops[i]];
		++bottomsCnt[bottoms[i]];
	}
	int result = size;

	for (int i = 1 ; i <= 6 ; ++i) {
		if (((mask >> i) & 1) == 0) {
			continue;
		}
		result = min({result, size - topCnt[i], size - bottomsCnt[i]});
	}
	return result;
}

