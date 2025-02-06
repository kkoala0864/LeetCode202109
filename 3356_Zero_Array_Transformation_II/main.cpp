#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 0, 6};
	vector<vector<int>> queries = {{1,2,1},{0,0,4},{1,1,5},{0,0,5},{1,2,4},{0,2,2},{2,2,4},{1,2,2},{1,2,4},{0,1,3}};
	Solution* test = new Solution();
	cout << test->minZeroArray(input, queries) << endl;
	return 0;
}

