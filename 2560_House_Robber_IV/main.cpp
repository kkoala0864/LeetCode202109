#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 5, 9};
	int k = 2;
	Solution *test = new Solution();
	cout << test->minCapability(input, k) << endl;
	return 0;
}
