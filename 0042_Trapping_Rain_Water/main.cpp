#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 2, 1, 2, 1, 5};
	Solution *test = new Solution();
	cout << test->trap(input) << endl;
	cout << test->trap2(input) << endl;
	return 0;
}
