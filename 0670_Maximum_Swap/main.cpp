#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int num = 2736;
	Solution *test = new Solution();
	cout << test->maximumSwap(num) << endl;
	return 0;
}
