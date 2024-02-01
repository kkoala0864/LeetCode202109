#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,0},{1,2},{3,2},{3,4}};
	Solution* test = new Solution();
	cout << test->minReorder(5, input) << endl;
	cout << test->minReorder2(5, input) << endl;
	return 0;
}

