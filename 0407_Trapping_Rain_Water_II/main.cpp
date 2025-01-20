#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	Solution* test = new Solution();
	cout << test->trapRainWater(input) << endl;
	return 0;
}

