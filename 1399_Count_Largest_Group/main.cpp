#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 264;
	Solution *test = new Solution();
	cout << test->countLargestGroup(n) << endl;
	return 0;
}
