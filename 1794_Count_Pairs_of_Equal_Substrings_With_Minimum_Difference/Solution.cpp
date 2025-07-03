#include <Solution.h>

int Solution::countQuadruples(string firstString, string secondString) {
	vector<int> pre(26, -1);
	vector<int> post(26, -1);

	for (int i = firstString.size() - 1 ; i >= 0 ; --i) {
		int idx = firstString[i] - 'a';
		pre[idx] = i;
	}
	for (int i = 0 ; i < secondString.size() ; ++i) {
		int idx = secondString[i] - 'a';
		post[idx] = i;
	}

	int minDiff = INT_MAX;
	int result = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		if (pre[i] == -1 || post[i] == -1) continue;
		int diff = pre[i] - post[i];
		if (diff < minDiff) {
			minDiff = diff;
			result = 0;
		}
		if (diff == minDiff) ++result;
	}
	return result;
}
