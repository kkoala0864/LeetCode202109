#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
	Solution* test = new Solution();
	cout << test->uniquePathsIII(input) << endl;
	return 0;
}

