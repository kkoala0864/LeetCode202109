#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3354,4316,3259,4904};
	Solution* test = new Solution();
	cout << test->connectSticks(input) << endl;
	return 0;
}

