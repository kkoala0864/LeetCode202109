#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{-1, 1}, {-3, 1, 4}, {-2, -1, 0, 2}};
	Solution *test = new Solution();
	cout << test->maxDistance(input) << endl;
	return 0;
}
