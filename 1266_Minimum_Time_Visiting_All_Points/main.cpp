#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input  {{1,1},{3,4},{-1,0}};
	Solution* test = new Solution();
	cout << test->minTimeToVisitAllPoints(input) << endl;
	return 0;
}

