#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
	Solution* test = new Solution();
	cout << test->maxMoves(input) << endl;
	return 0;
}

