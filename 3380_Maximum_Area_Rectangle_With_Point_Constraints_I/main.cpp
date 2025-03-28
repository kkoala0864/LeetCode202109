#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{96,44},{23,72},{96,72},{23,44},{65,44}};
	Solution* test = new Solution();
	cout << test->maxRectangleArea(input) << endl;
	return 0;
}

