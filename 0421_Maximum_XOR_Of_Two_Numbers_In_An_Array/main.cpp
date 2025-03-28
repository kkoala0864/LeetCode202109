#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 10, 5, 25, 2, 8};
	Solution *test = new Solution();
	cout << test->findMaximumXOR(input) << endl;
	return 0;
}
