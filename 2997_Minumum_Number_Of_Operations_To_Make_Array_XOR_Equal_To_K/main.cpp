#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 1, 3, 4};
	int k = 1;
	Solution *test = new Solution();
	cout << test->minOperations(input, 1) << endl;
	return 0;
}
