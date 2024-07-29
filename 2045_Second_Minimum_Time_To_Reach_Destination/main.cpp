#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{1,3},{1,4},{3,4},{4,5}};
	int n = 5;
	int time = 3;
	int change = 5;
	Solution* test = new Solution();
	cout << test->secondMinimum(n, input, time, change) << endl;
	return 0;
}

