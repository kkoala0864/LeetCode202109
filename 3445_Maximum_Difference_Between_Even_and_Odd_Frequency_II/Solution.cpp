#include <Solution.h>

int getStatus(int a, int b) {
	return ((a & 1) << 1) | (b & 1);
}

int Solution::maxDifference(string s, int k) {
	int size = s.size();
	int result = INT_MIN;

	for (int a = 0 ; a < 5 ; ++a) {
		for (int b = 0 ; b < 5 ; ++b) {
			if (a == b) continue;

			vector<int> best(4, INT_MAX);

			int cnta = 0, cntb = 0;
			int prea = 0, preb = 0;

			int l = -1;
			// same l just calculate once and store in to best vector
			// so time complexity is O(N)
			for (int r = 0 ; r < size ; ++r) {
				cnta += ((s[r] - '0') == a);
				cntb += ((s[r] - '0') == b);
				while (r - l >= k && cntb - preb >= 2) {
					int lStatus = getStatus(prea, preb);
					best[lStatus] = min(best[lStatus], prea - preb);
					++l;
					prea += ((s[l] - '0') == a);
					preb += ((s[l] - '0') == b);
				}
				int rStatus = getStatus(cnta, cntb);
				if (best[rStatus ^ 0b10] != INT_MAX) {
					result = max(result, cnta - cntb - best[rStatus ^ 0b10]);
				}
			}
		}
	}
	return result;
}
