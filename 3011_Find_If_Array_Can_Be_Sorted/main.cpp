#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {75, 34, 30};
	Solution* test = new Solution();
	cout << test->canSortArray(input) << endl;
	return 0;
}

