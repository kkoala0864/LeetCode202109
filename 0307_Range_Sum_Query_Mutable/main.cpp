#include <Solution3.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	vector<int> input = {1,3,5};
	NumArray* test = new NumArray(input);
	cout << test->sumRange(0,2) << endl;
	test->update(1,2);
	cout <<test->sumRange(0,2) <<endl;
	return 0;
}

