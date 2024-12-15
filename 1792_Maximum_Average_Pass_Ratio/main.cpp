#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,4},{3,9},{4,5},{2,10}};
	int k = 4;
	Solution* test = new Solution();
	cout << test->maxAverageRatio(input, k) << endl;
	return 0;
}

