#include <Solution4.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	vector<int> input = {9, -8};
	NumArray *test = new NumArray(input);
	test->update(0, 3);
	cout << test->sumRange(1, 1) << endl;
	cout << test->sumRange(0, 1) << endl;
	return 0;
}
