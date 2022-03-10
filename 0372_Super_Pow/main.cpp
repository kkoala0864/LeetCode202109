#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 0, 0};
	Solution* test = new Solution();
	cout << test->superPow(2147483647, input) << endl;
	cout << test->superPow2(2147483647, input) << endl;
	return 0;
}

