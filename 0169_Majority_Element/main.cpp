#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 2, 2, 1, 1, 2, 1};
	Solution *test = new Solution();
	cout << test->majorityElement(input) << endl;
	cout << test->majorityElement2(input) << endl;
	return 0;
}
