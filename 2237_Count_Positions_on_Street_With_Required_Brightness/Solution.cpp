#include <Solution.h>

int Solution::meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
	vector<int> b(n + 2, 0);
	for (const auto& l : lights) {
		++b[max(0, l[0] - l[1])];
		--b[min(n-1, l[0] + l[1]) + 1];
	}
	int result = 0;
	int cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		cnt += b[i];
		if (cnt >= requirement[i]) {
			++result;
		}
	}
	return result;
}
