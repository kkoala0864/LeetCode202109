#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,4,5},{1,2,6},{7,4,6}};
	Solution* test = new Solution();
	cout << test->maximumMinimumPath(input) << endl;
	return 0;
}

