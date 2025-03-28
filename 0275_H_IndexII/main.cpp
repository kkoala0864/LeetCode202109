#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 1, 3, 5, 6};
	Solution *test = new Solution();
	cout << test->hIndex(input) << endl;
	cout << test->hIndex2(input) << endl;
	return 0;
}
