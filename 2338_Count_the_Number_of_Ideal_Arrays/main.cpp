#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 2;
	int maxValue = 5;
	Solution *test = new Solution();
	cout << test->idealArrays(n, maxValue) << endl;
	return 0;
}
