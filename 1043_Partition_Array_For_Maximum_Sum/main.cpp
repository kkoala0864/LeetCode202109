#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,15,7,9,2,5,10};
	Solution* test = new Solution();
	cout << test->maxSumAfterPartitioning(input, 3) << endl;
	return 0;
}

