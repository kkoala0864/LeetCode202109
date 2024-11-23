#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,3,2,1};
	vector<vector<int>> query = {{1,3},{0,2}};
	Solution* test = new Solution();
	cout << test->isZeroArray(input, query) << endl;
	return 0;
}

