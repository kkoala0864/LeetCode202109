#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	Solution *test = new Solution();
	cout << test->getPermutation(3, 1) << endl;
	cout << test->getPermutation3(3, 3) << endl;
	cout << test->getPermutation3(3, 4) << endl;
	cout << test->getPermutation3(3, 5) << endl;
	return 0;
}
