#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,6,18};
	Solution* test = new Solution();
	cout << test->numFactoredBinaryTrees(input) << endl;
	return 0;
}

