#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,10},{2,5},{4,7},{3,9}};
	Solution* test = new Solution();
	cout << test->maximumUnits(input, 10) << endl;
	return 0;
}

