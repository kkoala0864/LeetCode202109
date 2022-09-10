#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,0,1},{0,0,0},{1,0,1}};
	Solution* test = new Solution();
	//cout << test->maxDistance(input) << endl;
	cout << test->maxDistance2(input) << endl;
	return 0;
}

