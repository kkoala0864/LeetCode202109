#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,2,3,1};
	Solution* test = new Solution();
	cout << test->reversePairs(input) << endl;
	return 0;
}

