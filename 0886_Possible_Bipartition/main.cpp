#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,9},{4,7},{1,3},{4,8},{5,6},{6,9},{8,9},{3,7},{2,5},{5,8},{1,2},{6,7},{3,10},{1,5},{3,6},{3,5},{2,6},{7,10},{4,5},{1,4},{2,10},{9,10},{3,9},{2,3},{6,8},{4,9},{7,9},{5,10},{4,6},{5,7},{7,8}};
	Solution* test = new Solution();
	cout << test->possibleBipartition(10, input) << endl;
	return 0;
}

