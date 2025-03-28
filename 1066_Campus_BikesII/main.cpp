#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> workers = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}};
	vector<vector<int>> bikes = {{0, 999}, {1, 999}, {2, 999}, {3, 999}, {4, 999}};
	Solution *test = new Solution();
	cout << test->assignBikes(workers, bikes) << endl;
	return 0;
}
