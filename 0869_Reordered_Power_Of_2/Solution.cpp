#include <Solution.h>

vector<int> getCnt(int v) {
	vector<int> dCnt(10, 0);
	while (v > 0) {
		++dCnt[v % 10];
		v /= 10;
	}
	return dCnt;
}

bool check(vector<int>& lhs, vector<int>& rhs) {
	for (int i = 0 ; i < 10 ; ++i) {
		if (lhs[i] != rhs[i]) return false;
	}
	return true;
}

bool Solution::reorderedPowerOf2(int n) {
	auto nCnt = getCnt(n);

	for (int i = 0 ; i < 32 ; ++i) {
		auto cCnt = getCnt(1 << i);
		if (check(nCnt, cCnt)) return true;
	}
	return false;
}
