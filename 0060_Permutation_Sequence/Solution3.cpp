#include <Solution.h>
#include <iostream>
#include <vector>

using namespace std;

string Solution::getPermutation3(int n, int k) {
	int mod = 1;
	for (int i = 1 ; i < n ; ++i) mod *= i;
	string val;
	for (int i = 1 ; i <= n ; ++i) val.push_back(i+'0');

	--k;
	string result;
	for (int i = n-1 ; i >= 1 ; --i) {
		int cnt = k / mod;
		k %= mod;
		mod /= i;
		result.push_back(val[cnt]);
		val.erase(val.begin() + cnt);
	}
	result += val;
	return result;
}
