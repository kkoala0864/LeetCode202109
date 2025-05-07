#include <Solution.h>

int Solution::minTaps(int n, vector<int>& ranges) {
	vector<pair<int, int>> w;

	for (int i = 0 ; i < ranges.size() ; ++i) {
		if (ranges[i] == 0) continue;
		w.emplace_back(max(0, i - ranges[i]), min(n, i + ranges[i]));
	}
	sort(w.begin(), w.end());

	int idx = 0;
	int mostFar = 0;
	int curFar = 0;

	int result = 0;
	while (curFar < n) {
		while (idx < w.size() && w[idx].first <= curFar) {
			mostFar = max(mostFar, w[idx].second);
			++idx;
		}
		if (mostFar == curFar) return -1;
		++result;
		curFar = mostFar;
	}
	return result;
}
