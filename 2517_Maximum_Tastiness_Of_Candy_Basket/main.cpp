#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {13,5,1,8,21,2};
	Solution* test = new Solution();
	cout << test->maximumTastiness(input, 3) << endl;
	return 0;
}

