#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int start = 10;
	int goal = 7;
	Solution *test = new Solution();
	cout << test->minBitFlips(10, 7) << endl;
	return 0;
}
