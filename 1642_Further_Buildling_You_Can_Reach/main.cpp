#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,5,1,2,3,4,10000};
	Solution* test = new Solution();
	cout << test->furthestBuilding(input, 4, 1) << endl;
	return 0;
}

