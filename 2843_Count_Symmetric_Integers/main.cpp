#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int low = 1;
	int high = 100;
	Solution *test = new Solution();
	cout << test->countSymmetricIntegers(low, high) << endl;
	return 0;
}
