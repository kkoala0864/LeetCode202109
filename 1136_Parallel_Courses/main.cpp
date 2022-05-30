#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,3},{3,1}};
	Solution* test = new Solution();
	cout << test->minimumSemesters(3, input) << endl;
	return 0;
}

