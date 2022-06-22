#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,1,5,6,4};
	Solution* test = new Solution();
	cout << test->findKthLargest(input, 2) << endl;
	cout << test->findKthLargest2(input, 2) << endl;
	cout << test->findKthLargest3(input, 2) << endl;
	return 0;
}

