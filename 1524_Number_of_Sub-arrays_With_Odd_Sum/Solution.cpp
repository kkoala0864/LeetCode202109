#include <Solution.h>
#include <iostream>

int Solution::numOfSubarrays(vector<int>& arr) {
	int odd = 0;
	int even = 1;
	int sum = 0;
	int result = 0;
	int mod = 1e9 + 7;
	for (const auto& v : arr) {
		sum += v;
		if (sum & 1) {
			result += even;
			result %= mod;
			++odd;
		} else {
			result += odd;
			result %= mod;
			++even;
		}
	}
	return result;
}
