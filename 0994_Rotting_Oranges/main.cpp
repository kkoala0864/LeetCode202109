#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,1,1},{1,1,0},{0,1,1}};
	Solution* test = new Solution();
	cout << test->orangesRotting3(input) << endl;
	return 0;
}

