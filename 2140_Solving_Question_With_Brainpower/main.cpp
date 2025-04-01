#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}};
	Solution *test = new Solution();
	cout << test->mostPoints(input) << endl;
	return 0;
}
