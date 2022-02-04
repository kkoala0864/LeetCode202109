#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;

string Solution::getPermutation2(int n, int k) {
	vector<int> fact(1,1);
	for (int i = 1 ; i <= n ; ++i) {
		fact.emplace_back(fact.back() * i);
	}

	string str = "123456789";
	string result("");

	while (n) {
		int idx = (k-1) / fact[n-1];
		result.push_back(str[idx]);
		str.erase(str.begin() + idx);
		k -= (idx * fact[n-1]);
		--n;
	}
	return result;
}
