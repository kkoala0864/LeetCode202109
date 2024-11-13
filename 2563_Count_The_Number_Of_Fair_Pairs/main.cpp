#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,1,7,4,4,5};
	int low = 3;
	int high = 6;
	Solution* test = new Solution();
	cout << test->countFairPairs(input, low, high) << endl;
	return 0;
}

