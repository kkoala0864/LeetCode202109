#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7, 2, 5, 10, 8};
	Solution *test = new Solution();
	cout << test->splitArray(input, 2) << endl;
	return 0;
}
