#include <Solution.h>

int getPower(int n) {
	int result = 0;
	while (n > 1) {
		if (n & 1) {
			n *= 3;
			++n;
		} else {
			n = n >> 1;
		}
		++result;
	}
	return result;
}

int Solution::getKth(int lo, int hi, int k) {

	map<int, set<int>> m;
	for (int i = lo ; i <= hi ; ++i) {
		m[getPower(i)].emplace(i);
	}
	for (const auto& e : m) {
		if (e.second.size() < k) {
			k -= e.second.size();
		} else {
			for (const auto& v : e.second) {
				--k;
				if (k == 0) return v;
			}
		}
	}
	return -1;
}
