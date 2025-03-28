#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> e1 = {{0, 1}, {2, 0}, {3, 2}, {3, 6}, {8, 7}, {4, 8}, {5, 4}, {3, 5}, {3, 9}};
	vector<vector<int>> e2 = {{0, 1}, {0, 2}, {0, 3}};
	Solution *test = new Solution();
	cout << test->minimumDiameterAfterMerge(e1, e2) << endl;
	return 0;
}
