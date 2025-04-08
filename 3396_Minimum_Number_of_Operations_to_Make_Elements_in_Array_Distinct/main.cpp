#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4, 2, 3, 3, 5, 7};
	Solution *test = new Solution();
	cout << test->minimumOperations(input) << endl;
	return 0;
}
