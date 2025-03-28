#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

int Solution::sumDistance(vector<int>& nums, string s, int d) {
	int size = nums.size();

	vector<long long> endpoint;
	for (int i = 0 ; i < size ; ++i) {
		endpoint.emplace_back((long long)nums[i] + (long long)((s[i] == 'R' ? 1 : -1) * (long long)d));
	}
	sort(endpoint.begin(), endpoint.end());

	long long mod = 1e9 + 7;
	long long result = 0;
	for (int i = 1 ; i < size ; ++i) {
		long long len = endpoint[i] - endpoint[i-1];
		result += ((len * (long long)i % mod)* ((long long)size - (long long)i) % mod);
		result %= mod;
	}

	return result;
}
