#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
	Solution* test = new Solution();
	cout << test->findMaxFish(input) << endl;
	return 0;
}

