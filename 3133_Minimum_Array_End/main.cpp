#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	int x = 4;
	Solution* test = new Solution();
	cout << test->minEnd(n, x) << endl;
	return 0;
}

