#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1}};
	Solution* test = new Solution();
	cout << test->numDistinctIslands2(input) << endl;
	return 0;
}

