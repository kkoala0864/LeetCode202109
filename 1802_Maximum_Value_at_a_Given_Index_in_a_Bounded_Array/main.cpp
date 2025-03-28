#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	int index = 0;
	int maxSum = 4;
	Solution *test = new Solution();
	cout << test->maxValue(n, index, maxSum) << endl;
	return 0;
}
