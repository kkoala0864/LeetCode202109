#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->canMeasureWater(1, 2, 3) << endl;
	return 0;
}
