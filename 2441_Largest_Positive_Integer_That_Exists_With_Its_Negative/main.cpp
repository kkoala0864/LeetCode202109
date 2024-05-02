#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1,10,6,7,-7,1};
	Solution* test = new Solution();
	cout << test->findMaxK(input) << endl;
	return 0;
}

