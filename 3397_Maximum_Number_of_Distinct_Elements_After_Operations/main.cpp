#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,1,1,1,1,1,5,5,5};
	int k = 3;
	Solution* test = new Solution();
	cout << test->maxDistinctElements(input, k) << endl;
	return 0;
}

