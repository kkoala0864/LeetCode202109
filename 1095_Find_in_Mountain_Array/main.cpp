#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4, 5, 3, 1};
	MountainArray mountainArray(input);
	int target = 3;
	Solution *test = new Solution();
	cout << test->findInMountainArray(target, mountainArray) << endl;
	return 0;
}
