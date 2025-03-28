#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {14, 3, 19, 3};
	Solution *test = new Solution();
	cout << test->furthestBuilding(input, 17, 0) << endl;
	cout << test->furthestBuilding2(input, 17, 0) << endl;
	return 0;
}
