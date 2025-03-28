#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7, 7, 7, 7, 12, 7, 7};
	int m = 2;
	int k = 3;
	Solution *test = new Solution();
	cout << test->minDays(input, m, k) << endl;
	return 0;
}
