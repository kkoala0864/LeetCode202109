#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{10,13,22,28,32,35,43},{2,11,15,25,27},{6,13,18,25,42},{5,6,20,27,37,47},{7,11,19,23,35},{7,11,17,25,31,43,46,48},{1,4,10,16,25,26,46},{7,11},{3,9,19,20,21,24,32,45,46,49},{11,41}};
	Solution* test = new Solution();
	cout << test->numBusesToDestination(input, 37, 43) << endl;
	cout << test->numBusesToDestination2(input, 37, 43) << endl;
	return 0;
}

