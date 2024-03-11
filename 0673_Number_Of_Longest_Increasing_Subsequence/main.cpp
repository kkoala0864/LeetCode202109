#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,4,3,5,4,7,2};
	Solution* test = new Solution();
	cout << test->findNumberOfLIS(input) << endl;
	cout << test->findNumberOfLIS2(input) << endl;
	return 0;
}

