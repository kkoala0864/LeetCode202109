#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int l = 5, r = 7;
	Solution* test = new Solution();
	cout << test->nonSpecialCount(l, r) << endl;
	return 0;
}

