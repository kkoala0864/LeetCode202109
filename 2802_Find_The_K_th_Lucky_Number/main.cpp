#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int input = 1000;
	Solution* test = new Solution();
	cout << test->kthLuckyNumber(input) << endl;
	return 0;
}

