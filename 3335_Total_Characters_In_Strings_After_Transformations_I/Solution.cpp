#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int Solution::lengthAfterTransformations(string s, int t) {
	int mod = 1e9 + 7;
	int times = t / 26;
	int rest = t % 26;
	int base = 0;
	vector<int> cnt(26, 0), next(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];
	next = cnt;
	for (int j = 0 ; j < times ; ++j) {
		for (int i = 1 ; i < 26 ; ++i) {
			next[i] = (next[i] + cnt[i-1]) % mod;
		}
		next[0] = (next[0] + cnt[25]) % mod;
		next[1] = (next[1] + cnt[25]) % mod;
		cnt = next;
	}

	for (int i = 0 ; i < rest ; ++i) {
		for (int i = 0 ; i < 26 ; ++i) next[i] = 0;
		for (int j = 1 ; j < 26 ; ++j) {
			next[j] = cnt[j-1];
		}
		next[0] = (next[0] + cnt[25]) % mod;
		next[1] = (next[1] + cnt[25]) % mod;
		cnt = next;
	}
	int result = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		result += cnt[i];
		result %= mod;
	}
	return result;
}
