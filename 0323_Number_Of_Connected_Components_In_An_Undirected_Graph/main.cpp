#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{3,4}};
	Solution* test = new Solution();
	cout << test->countComponents(5, input) << endl;
	cout << test->countComponents2(5, input) << endl;
	return 0;
}

