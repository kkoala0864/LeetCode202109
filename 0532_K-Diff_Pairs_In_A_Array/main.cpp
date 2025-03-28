#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 4, 1, 5};
	Solution *test = new Solution();
	cout << test->findPairs(input, 2) << endl;
	return 0;
}
