#include <Solution.h>
#include <iostream>

int myPow(int a, int b) {
	a %= 1337;
	int result = 1;
	for (int i = 0 ; i < b ; ++i) {
		result *= a;
		result %= 1337;
	}
	return result;
}

int Solution::superPow(int a, vector<int>& b) {
	int res = 1, x, f;
	for (const auto& iter : b) {
		x = myPow(a, iter);
		x *= res;
		x %= 1337;
		f = x;
		x = myPow(x, 10);
		res = x;
	}
	return f;
}
