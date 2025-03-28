#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->largestGoodInteger("6777133339") << endl;
	return 0;
}
