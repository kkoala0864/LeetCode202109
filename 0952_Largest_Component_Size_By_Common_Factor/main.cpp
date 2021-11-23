#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,6,7,4,12,21,39};
	Solution* test = new Solution();
	cout << test->largestComponentSize(input) << endl;
	return 0;
}

