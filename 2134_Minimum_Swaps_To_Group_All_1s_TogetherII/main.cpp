#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,0,0,1,0,1,1,0};
	Solution* test = new Solution();
	cout << test->minSwaps(input) << endl;
	return 0;
}

