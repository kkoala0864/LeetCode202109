#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,6,5};
	int n = 5;
	int maxSum = 6;
	Solution* test = new Solution();
	cout << test->maxCount(input, n, maxSum) << endl;
	return 0;
}

