#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 7, 10, 0};
	int k = 1;
	Solution *test = new Solution();
	cout << test->largestInteger(input, k) << endl;
	return 0;
}
