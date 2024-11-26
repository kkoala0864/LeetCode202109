#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,2},{1,3},{1,2}};
	Solution* test = new Solution();
	cout << test->findChampion(4, input) << endl;
	return 0;
}

