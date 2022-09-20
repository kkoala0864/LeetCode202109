#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{1,3},{2,4}};
	Solution* test = new Solution();
	cout << test->possibleBipartition(4, input) << endl;
	cout << test->possibleBipartition2(4, input) << endl;
	return 0;
}

