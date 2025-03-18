#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,8,48,10};
	Solution* test = new Solution();
	cout << test->longestNiceSubarray(input) << endl;
	return 0;
}

