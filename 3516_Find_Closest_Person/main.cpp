#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int x = 2;
	int y = 7;
	int z = 4;
	Solution *test = new Solution();
	cout << test->findClosest(x, y, z) << endl;
	return 0;
}
