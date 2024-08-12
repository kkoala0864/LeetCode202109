#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,4,6};
	Solution* test = new Solution();
	cout << test->tupleSameProduct(input) << endl;
	return 0;
}

