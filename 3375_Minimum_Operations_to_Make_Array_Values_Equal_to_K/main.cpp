#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,2,5,4,5};
	int k = 2;
	Solution *test = new Solution();
	cout << test->minOperations(input, k) << endl;
	return 0;
}
