#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7,5,9};
	int k = 4;
	Solution* test = new Solution();
	cout << test->maxLength(input, k) << endl;
	return 0;
}

