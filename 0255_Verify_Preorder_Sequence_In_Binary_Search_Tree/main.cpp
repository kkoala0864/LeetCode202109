#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 1};
	Solution *test = new Solution();
	cout << test->verifyPreorder(input) << endl;
	return 0;
}
