#include <Solution.h>
#include <iostream>

string Solution::subStrHash(string s, int power, int modulo, int k, int hashValue) {
	int base = 1;
	power = power % modulo;
	auto Val = [] (char c) { return c - 'a' + 1; };
	long long sum = Val(s[s.size() - 1]);
	long long bigP = power;
	int res = 0;
	int size = s.size();
	for (int i = size - 2 ; i >= (size - k) ; --i) {
		sum = ((sum * power) + Val(s[i])) % modulo;
		bigP = (bigP * power) % modulo;
	}
	if (sum == hashValue) res = size - k;

	for (int i = size - k - 1; i >= 0 ; --i) {
		sum = ((sum * power) + Val(s[i])) % modulo;
		sum = (modulo + sum - (Val(s[i+k]) * bigP) % modulo) % modulo;
		if (sum == hashValue) res = i;
	}
	return s.substr(res, k);
}
