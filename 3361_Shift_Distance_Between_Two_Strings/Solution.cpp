#include <Solution.h>

long long Solution::shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
	vector<long long> nCost(26, 0), pCost(26, 0);
	nCost[0] = nextCost[0];
	for (int i = 1 ; i < 26 ; ++i) {
		nCost[i] = nCost[i-1] + nextCost[i];
	}
	pCost[25] = previousCost[25];
	for (int i = 24 ; i >= 0 ; --i) {
		pCost[i] = pCost[i+1] + previousCost[i];
	}
	long long result = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		int cc = s[i] - 'a';
		int tc = t[i] - 'a';
		int v = 0;
		if (tc == cc) continue;
		long long nc = 0, pc = 0;
		if (tc > cc) {
			nc = nCost[tc-1] - (cc == 0 ? 0 : nCost[cc-1]);
			pc = pCost[0] - pCost[cc + 1] + (tc == 25 ? 0 : pCost[tc + 1]);
		} else {
			nc = nCost[25] - nCost[cc-1] + (tc == 0 ? 0 : nCost[tc-1]);
			pc = pCost[tc + 1] - (cc == 25 ? 0 : pCost[cc+1]);
		}
		result += min(nc, pc);
	}
	return result;
}
