#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 5, 0, 4, 1, 3};
	Solution *test = new Solution();
	cout << test->increasingTriplet(input) << endl;
	cout << test->increasingTriplet2(input) << endl;
	return 0;
}
