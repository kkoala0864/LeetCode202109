#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0},{0,2},{1,1},{2,0},{2,2}};
	Solution* test = new Solution();
	cout << test->removeStones(input) << endl;
	return 0;
}

