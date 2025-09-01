#include <Solution.h>

int getDis(const vector<int>& w, const vector<int>& b) {
	return abs(w[1] - b[1]) + abs(w[0] - b[0]);
}

int getBitSize(int v) {
	int cnt = 0;
	while (v > 0) {
		++cnt;
		v &= (v-1);
	}
	return cnt;
}

int Solution::assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
	unordered_map<int, int> m;
	m[0] = 0;

	for (int i = 0 ; i < workers.size() ; ++i) {
		unordered_map<int, int> nm;
		for (int j = 0 ; j < bikes.size() ; ++j) {
			for (const auto& e : m) {
				if (e.first & (1 << j)) continue;
				int mask = e.first | (1 << j);
				int nOffset = e.second + getDis(workers[i], bikes[j]);
				if (nm.count(mask)) {
					nm[mask] = min(nm[mask], nOffset);
				} else {
					nm[mask] = nOffset;
				}
			}
		}
		m = std::move(nm);
	}
	int result = INT_MAX;
	for (const auto& e : m) {
		if (getBitSize(e.first) != workers.size()) continue;
		result = min(result, e.second);
	}
	return result;
}
