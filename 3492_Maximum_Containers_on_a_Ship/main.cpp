#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 2;
	int w = 3;
	int maxWeight = 15;
	Solution *test = new Solution();
	cout << test->maxContainers(n, w, maxWeight) << endl;
	return 0;
}
