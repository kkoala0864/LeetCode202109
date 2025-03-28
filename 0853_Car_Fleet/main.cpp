#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int target = 12;
	vector<int> position = {10, 8, 0, 5, 3};
	vector<int> speed = {2, 4, 1, 1, 3};
	Solution *test = new Solution();
	cout << test->carFleet(target, position, speed) << endl;
	return 0;
}
