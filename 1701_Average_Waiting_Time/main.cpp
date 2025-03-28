#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
	Solution *test = new Solution();
	cout << test->averageWaitingTime(input) << endl;
	return 0;
}
