#include <Solution.h>

vector<long long> Solution::maximumEvenSplit(long long finalSum) {
	if (finalSum & 1) return vector<long long>();

	unordered_set<long long> us;
	long long sum = 0;
	for (long long i = 2 ; i <= finalSum ; i += 2) {
		sum += i;
		us.emplace(i);
		if (sum < finalSum) continue;
		if (sum >= finalSum) break;
	}
	if (sum > finalSum) {
		long long diff = sum - finalSum;
		us.erase(diff);
	}
	vector<long long> result(us.begin(), us.end());
	return result;
}
