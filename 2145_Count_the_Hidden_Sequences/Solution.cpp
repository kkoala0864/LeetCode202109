#include <Solution.h>
#include <iostream>
#include <climits>

int Solution::numberOfArrays(vector<int>& differences, int lower, int upper) {
	long long ms = 0, mb = 0;

	long long offset = 0;
	for (const auto& v : differences) {
		offset += v;
		ms = min(ms, offset);
		mb = max(mb, offset);
	}
	long long maxOffset = mb - ms + 1;
	long long totalOffset = upper - lower + 1;
	long long result = max((long long)0, totalOffset - maxOffset + 1);
	return result;
}
