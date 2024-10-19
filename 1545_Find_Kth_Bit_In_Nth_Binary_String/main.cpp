#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	int k = 2;
	Solution* test = new Solution();
	cout << test->findKthBit(n, k) << endl;
	return 0;
}

