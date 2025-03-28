#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, -2, 4};
	Solution *test = new Solution();
	cout << test->maxProduct(input) << endl;
	cout << test->maxProduct2(input) << endl;
	cout << test->maxProduct3(input) << endl;
	cout << test->maxProduct4(input) << endl;
	cout << test->maxProduct5(input) << endl;
	return 0;
}
