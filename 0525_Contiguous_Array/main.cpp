#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 1, 0};
	Solution *test = new Solution();
	cout << test->findMaxLength(input) << endl;
	return 0;
}
