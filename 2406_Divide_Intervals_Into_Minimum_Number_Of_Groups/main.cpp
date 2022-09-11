#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,10},{6,8},{1,5},{2,3},{1,10}};
	Solution* test = new Solution();
	cout << test->minGroups(input) << endl;
	return 0;
}

