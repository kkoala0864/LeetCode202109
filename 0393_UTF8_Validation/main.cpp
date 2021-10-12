#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {235,140,4};
	Solution* test = new Solution();
	cout << test->validUtf8(input) << endl;
	return 0;
}

