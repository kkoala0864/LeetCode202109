#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 11, 10, 1, 3};
	int k = 10;
	Solution *test = new Solution();
	cout << test->minOperations(input, k) << endl;
	return 0;
}
