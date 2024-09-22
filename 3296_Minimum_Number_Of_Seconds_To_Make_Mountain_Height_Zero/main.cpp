#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> workerTimes = {3,2,2,4};
	int mountainHeight = 10;
	Solution* test = new Solution();
	cout << test->minNumberOfSeconds(mountainHeight, workerTimes) << endl;
	return 0;
}

