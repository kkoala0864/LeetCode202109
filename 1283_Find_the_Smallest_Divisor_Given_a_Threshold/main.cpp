#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {44,22,33,11,1};
	int threshold = 5;
	Solution* test = new Solution();
	cout << test->smallestDivisor(input, threshold) << endl;
	return 0;
}

