#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,0}};
	Solution* test = new Solution();
	cout << test->validPath(3, input, 0, 2) << endl;
	return 0;
}

