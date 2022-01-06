#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-2, 0, -1};
	Solution* test = new Solution();
	cout << test->maxProduct(input) << endl;
	cout << test->maxProduct2(input) << endl;
	cout << test->maxProduct3(input) << endl;
	return 0;
}

