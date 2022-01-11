#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7,7,7,7,7,7,7};
	Solution* test = new Solution();
	cout << test->lengthOfLIS(input) << endl;
	cout << test->lengthOfLIS2(input) << endl;
	cout << test->lengthOfLIS3(input) << endl;
	return 0;
}

