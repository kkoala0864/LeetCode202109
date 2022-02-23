#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {248, 130, 130, 130};
	Solution* test = new Solution();
	cout << test->validUtf8(input) << endl;
	cout << test->validUtf82(input) << endl;
	return 0;
}

