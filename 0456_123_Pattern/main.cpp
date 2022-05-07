#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,0,1,-4,-3};
	Solution* test = new Solution();
	cout << test->find132pattern(input) << endl;
	return 0;
}

