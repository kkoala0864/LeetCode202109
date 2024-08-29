#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	Solution* test = new Solution();
	cout << test->removeStones2(input) << endl;
	cout << test->removeStones3(input) << endl;
	cout << test->removeStones4(input) << endl;
	return 0;
}

