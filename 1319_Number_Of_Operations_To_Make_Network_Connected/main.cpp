#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{0,2},{0,3},{1,2}};
	Solution* test = new Solution();
	cout << test->makeConnected(6, input) << endl;
	return 0;
}
