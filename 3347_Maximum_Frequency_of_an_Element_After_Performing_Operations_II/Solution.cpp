#include <Solution.h>

void check(long long i, long long k, const vector<long long>& value, const vector<long long>& preSum, map<long long, long long>& m, long long& result, long long numOperations) {
	long long l = i - k;
	long long r = i + k;

	long long li = lower_bound(value.begin(), value.end(), l) - value.begin();
	long long ri = upper_bound(value.begin(), value.end(), r) - value.begin();
	--ri;

	if (ri < li) return;
	long long cur = m.count(i) ? m[i] : 0;
	long long convert = preSum[ri] - (li > 0 ? preSum[li-1] : 0) - cur;
	result = max(result, cur + min(convert, numOperations));
}

int Solution::maxFrequency(vector<int>& nums, int k, int numOperations) {
	map<long long, long long> m;
	for (const auto& v : nums) ++m[v];

	vector<long long> value;
	vector<long long> cnt;
	for (const auto& e : m) {
		value.emplace_back(e.first);
		cnt.emplace_back(e.second);
	}

	vector<long long> preSum(cnt.size(), 0);
	for (long long i = 0 ; i < cnt.size() ; ++i) {
		preSum[i] = (i > 0 ? preSum[i-1] : 0) + cnt[i];
	}

	long long result = 0;
	for (long long i = 0 ; i < value.size() ; ++i) {
		check(value[i] - k, k, value, preSum, m, result, numOperations);
		check(value[i], k, value, preSum, m, result, numOperations);
		check(value[i] + k, k, value, preSum, m, result, numOperations);
	}
	return result;
}
