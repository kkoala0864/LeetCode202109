#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,2,-1}};
	Solution* test = new Solution();
	cout << test->maxSumSubmatrix(input, 3) << endl;
	return 0;
}

