#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
	int n = 6;
	Solution* test = new Solution();
	cout << test->earliestAcq(input, n) << endl;
	return 0;
}

