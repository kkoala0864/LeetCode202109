#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int m = 2, n = 2;
	Solution *test = new Solution();
	cout << test->numberOfPatterns(m, n) << endl;
	return 0;
}
