#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1}, {0}};
	Solution* test = new Solution();
	cout << test->shortestDistance(input) << endl;
	return 0;
}

