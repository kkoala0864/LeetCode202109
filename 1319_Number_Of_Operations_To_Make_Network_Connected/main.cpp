#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{0,2},{1,2}};
	Solution* test = new Solution();
	cout << test->makeConnected(4, input) << endl;
	cout << test->makeConnected2(4, input) << endl;
	return 0;
}

