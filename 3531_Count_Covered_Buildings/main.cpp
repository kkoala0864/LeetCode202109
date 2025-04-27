#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1},{1,2},{2,1},{2,2}};
	int n = 3;
	Solution *test = new Solution();
	cout << test->countCoveredBuildings(n, input) << endl;
	return 0;
}
