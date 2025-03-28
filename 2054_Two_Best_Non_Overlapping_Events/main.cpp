#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{10, 83, 53}, {63, 87, 45}, {97, 100, 32}, {51, 61, 16}};
	Solution *test = new Solution();
	cout << test->maxTwoEvents(input) << endl;
	return 0;
}
