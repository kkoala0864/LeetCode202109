#include <Solution.h>

char Solution::kthCharacter(long long k, vector<int>& operations) {
	--k;

	int size = operations.size();

	long long bit = size;
	long long v = 0;
	for (long long i = min(64, size) - 1 ; i >= 0 ; --i) {
		if (k & (1LL << i) && operations[i] == 1) {
			++v;
		}
	}
	return (v % 26) + 'a';
}
