#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 1777;
	Solution *test = new Solution();
	cout << test->magicalString(n) << endl;
	return 0;
}
