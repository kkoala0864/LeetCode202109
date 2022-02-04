#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	Solution* test = new Solution();
	cout << test->getPermutation(3, 1) << endl;
	cout << test->getPermutation2(3, 1) << endl;
	return 0;
}

