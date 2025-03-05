#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	Solution* test = new Solution();
	cout << test->coloredCells(n) << endl;
	return 0;
}

