#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5,6,7,8};
	Solution* test = new Solution();
	cout << test->maxWeight(input) << endl;
	return 0;
}

