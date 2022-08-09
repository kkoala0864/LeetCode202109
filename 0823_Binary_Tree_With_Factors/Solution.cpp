#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::sort;

int Solution::numFactoredBinaryTrees(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	unordered_map<int, long> uM;
	long mod = 1e9 + 7;
	int result = 0;
	for (int i = 0 ; i < arr.size() ; ++i) {
		long local = 0;
		for (const auto& v : uM) {
			if (arr[i] % v.first != 0) continue;
			int rest = arr[i] / v.first;
			if (uM.find(rest) == uM.end()) continue;
			local += ((uM[rest] * v.second) % mod);
			local %= mod;
		}
		uM[arr[i]] = (local + 1);
		uM[arr[i]] %= mod;
		result += uM[arr[i]];
		result %= mod;
	}
	return result;
}
