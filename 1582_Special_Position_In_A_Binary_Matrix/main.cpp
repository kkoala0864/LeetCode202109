#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
	Solution *test = new Solution();
	cout << test->numSpecial(input) << endl;
	return 0;
}
