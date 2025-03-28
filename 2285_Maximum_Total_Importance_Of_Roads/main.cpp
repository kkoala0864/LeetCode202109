#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 3}, {2, 4}, {1, 3}};
	int n = 5;
	Solution *test = new Solution();
	cout << test->maximumImportance(n, input) << endl;
	return 0;
}
