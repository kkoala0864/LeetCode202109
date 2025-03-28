#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> primes = {2, 7, 13, 19};
	int n = 12;
	Solution *test = new Solution();
	cout << test->nthSuperUglyNumber(n, primes) << endl;
	return 0;
}
