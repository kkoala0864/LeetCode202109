#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,4,5};
	Solution *test = new Solution();
	cout << test->sumOfGoodSubsequences(input) << endl;
	return 0;
}
