#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,4},{6,8}};
	int x = 2;
	Solution* test = new Solution();
	cout << test->minOperations(input, x) << endl;
	return 0;
}

