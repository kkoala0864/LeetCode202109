#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}};
	Solution *test = new Solution();
	cout << test->canFinish(20, input) << endl;
	cout << test->canFinish2(20, input) << endl;
	cout << test->canFinish3(20, input) << endl;
	return 0;
}
