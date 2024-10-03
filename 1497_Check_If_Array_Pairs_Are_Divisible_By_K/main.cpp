#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5,6};
	int k = 10;
	Solution* test = new Solution();
	cout << test->canArrange(input, k) << endl;
	return 0;
}

