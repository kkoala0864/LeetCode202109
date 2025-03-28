#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4, 0, 5, -5, 3, 3, 0, -4, -5};
	Solution *test = new Solution();
	cout << test->threeSumClosest(input, -2) << endl;
	cout << test->threeSumClosest2(input, -2) << endl;
	cout << test->threeSumClosest3(input, -2) << endl;
	return 0;
}
