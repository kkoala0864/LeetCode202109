#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9, 3, 5};
	Solution *test = new Solution();
	cout << test->isPossible(input) << endl;
	return 0;
}
