#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1}, {2}, {3}, {}};
	Solution *test = new Solution();
	cout << test->canVisitAllRooms(input) << endl;
	cout << test->canVisitAllRooms2(input) << endl;
	return 0;
}
