#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,7,9,3,1};
	Solution* test = new Solution();
	cout << test->rob(input) << endl;
	cout << test->rob2(input) << endl;
	return 0;
}

