#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,3,1,1,3,3,2};
	Solution* test = new Solution();
	cout << test->findLeastNumOfUniqueInts(input, 3) << endl;
	return 0;
}

