#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {197,130,1};
	Solution* test = new Solution();
	cout << test->validUtf8(input) << endl;
	cout << test->validUtf82(input) << endl;
	cout << test->validUtf83(input) << endl;
	return 0;
}

